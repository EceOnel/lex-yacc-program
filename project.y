
%{
	#include <stdio.h>
	#include <iostream>
	#include <string>
	#include <vector>
	using namespace std;
	#include "y.tab.h"
	extern FILE *yyin;
	extern int yylex();
	extern int linenum;
	void yyerror(string s);
	int integer = 0;
	int flo = 0;
	int str = 0;
	int variable = 0;
	int ifloop = 0;
	int ifloopcount = 0;
	int tabcount = 0;
    int Ifelseelif = 0;
    int alreadyin = 0;
	vector<string> variable_int;
	vector<string> variable_float;			
	vector<string> variable_string;
	vector<string>	output;
	vector<string>	output1;
	vector<string> assignment;
	vector<string> loopbody;
    vector<int> iftabcount;	

%}

%union
{
	int value;
	char * str;
	int tab;
}


%token EQUAL IF ELSE ELIF COLON NWLINE
%token<str> VAR INT STRING OP FLOAT COMPARISON 
%left NWLINE
%type<str> body statements statement assignment assign Condition If_else_elif
%token<tab> TAB

%start body

%%
body:
    statements
    {
        //for empty if else elif block error
        string lasttemp = string($1);
        int mylinenum = 1;
        int bracetcount = 0;
        int parop = 0;
        for(int i = 0; i < lasttemp.length(); i++)
        {
            if(lasttemp[i] == '\n'){
                    mylinenum ++;
            }
            if(lasttemp[i] == '{')
            {
                parop = 1;
                bracetcount ++;
                i++;
                while((lasttemp[i] == '\t')|(lasttemp[i] == '\n')){
                    i++;
                    if(lasttemp[i] == '\n'){
                        mylinenum ++;
                    }
                }
                if(lasttemp[i] == '}'){
                        cout<<"\rerror in line "<<(mylinenum - bracetcount)+1<<": at least one line should be inside if/elif/else block"<<endl;
                        return 0;
                    }
                else{
                    if(lasttemp[i] == '{'){
                        bracetcount ++;
                        parop = 1;
                    }
                    if(lasttemp[i] == '}'){
                        bracetcount ++;
                        parop = 0; 
                    }
                }
            }
        }
        
        //for elif after else error
        
        int ifcount = 0;
        int mynewline = 1;
        int bracetcount2 = 0;
        int tabcount1 = 1;
        int okay = 0;
        for(int i = 0; i < lasttemp.length()-4; i++)
        {
            if(lasttemp[i] == '\n')
            {
                mynewline ++;
                tabcount1 = 0;
            }
            if(lasttemp[i] == '\t')
            {
                tabcount1 ++;
            }
            if(lasttemp[i] == '{')
            {
                bracetcount2 ++;
            }
            if(lasttemp[i] == '}')
            {
                if(ifcount == tabcount1){
                    ifcount --;
                }
                bracetcount2 ++;
            }
            if((lasttemp[i-2] != 'e')&(lasttemp[i] == 'i')&&(lasttemp[i+1] == 'f'))
            {
                iftabcount.push_back(tabcount1);
                ifcount ++;
            }
            if((lasttemp[i] == 'e')&&(lasttemp[i+1] == 'l')&&(lasttemp[i+2] == 's')&&(lasttemp[i+3] == 'e')&&(lasttemp[i+5] != 'i')&&(lasttemp[i+6] != 'f') )
            {
                for(int i = 0; i < iftabcount.size(); i++){
                    if(iftabcount[i] == tabcount1){
                        iftabcount.erase(iftabcount.begin()+i);
                        okay = 1;
                    }
                }
                if(okay != 1)
                {
                    cout<<"\relse without if in line"<< mynewline - bracetcount2<<endl;
                    return 0;
                }
                okay = 0;
            }
            if((lasttemp[i] == 'e')&&(lasttemp[i+1] == 'l')&&(lasttemp[i+2] == 's')&&(lasttemp[i+3] == 'e')&&(lasttemp[i+5] == 'i')&&(lasttemp[i+6] == 'f'))
            {
                for(int i = 0; i < iftabcount.size(); i++){
                    if(iftabcount[i] == tabcount1){
                        okay = 1;
                    }
                }
                if(okay != 1)
                {
                    cout<<"\relif after else in line "<< mynewline - bracetcount2<<endl;
                    return 0;
                }
                okay = 0;
            }
        }


        cout<<"\rvoid main()\n{";
        if (variable_int.size() != 0)
        {
            cout<<"\n\tint ";
            for(int i = 0; i < variable_int.size() ; i++)
            {
                    cout<<variable_int[i]<<"_int";
                    if(i != variable_int.size()-1)
                        cout<<",";
            }
            if(variable_float.size() == 0)
                cout<<";\n";
            else
                cout<<";";
        }
        if (variable_float.size() != 0)
        {
            cout<<"\n\tfloat ";
            for(int i = 0; i < variable_float.size() ; i++)
            {
                    cout<<variable_float[i]<<"_flt";
                    if(i != variable_float.size()-1)
                        cout<<",";
            }
            if(variable_string.size() == 0)
                cout<<";\n";
            else
                cout<<";";
        }
        if (variable_string.size() != 0)
        {
            cout<<"\n\tstring ";
            for(int i = 0; i < variable_string.size() ; i++)
            {
                    cout<<variable_string[i]<<"_str";
                    if(i != variable_string.size()-1)
                        cout<<",";
            }
            cout<<";\n";
        }

        cout <<"\n"<< $1 << endl;
        cout<<"\n}\n";
    }
    ;

statements:
    statement
    {
        string finalline;
        if(ifloopcount > 0)
        {
            string parclose;
            for(int i = 1; i < ifloopcount; i++)
            {
                parclose = parclose + "\t";
            }
            string temp =  parclose + "\t}\n" +string($1);
            $1 = strdup(temp.c_str());
            ifloopcount = 0;
        }

        if(Ifelseelif == 1)
        {
            ifloopcount += 1;
            ifloop = 1;
            string temp = string($1)+"\n\t{";
            $1 = strdup(temp.c_str());
        }
        else{
            ifloop = 0;
        }
        finalline = string($1);
        $$ = strdup(finalline.c_str());
    }
    |
    TAB statement
    {
        int iftabcount = 0;
        string temp1;
        for(int i = 0; i< $1 ; i++)
        {
            temp1 = temp1 + "\t";
            iftabcount = iftabcount + 1;
        }
        string temp = temp1 + string($2);
        if((ifloop == 1)&&(ifloopcount == $1))
        {
            ifloop = 0;
        }
        if (ifloop == 1)
        {
            cout<<"\rtab inconsistency in line "<<linenum<<endl;
            return 0;
        }
        else if ($1 > ifloopcount)
        {
            cout<<"\rtab inconsistency in line "<<linenum<<endl;
            return 0;
        }
        else if ($1 < ifloopcount)
        {
            string parclose;
            for(int i = 0; i < ifloopcount - $1 ; i++)
            {
                for(int k = 1; k < ifloopcount - i;k++)
                {
                    parclose = parclose + "\t";
                }
                parclose = parclose + "\t}\n";
            }
            temp = parclose + temp;
            ifloopcount = $1;
        }
        if(Ifelseelif == 1)
        {
            ifloopcount = ifloopcount + 1;
            ifloop = 1;
            string temp4 ="\n";
            for(int i = 0; i < $1; i++)
            {
                temp4 = temp4 + "\t";
            }
            temp4 = temp4 + "\t{";
            temp =temp + temp4; 
        }
        $$ = strdup(temp.c_str());
    }
    |
    statements NWLINE statements
    {
        if(string($3)!="\n")
        {
            string temp = string($1) + "\n" + string($3);
            $$ = strdup(temp.c_str());
        }
    }
    ;

statement:
    assignment
    {
        Ifelseelif = 0;
        string temp = "\t"+string($1);
        $$ = strdup(temp.c_str());
    }
    |
    If_else_elif
    {
        //indicates that the line is if or else or elif
        Ifelseelif = 1;
        string temp = "\t"+string($1);
        $$ = strdup(temp.c_str());
    }
    |
    //empty for detecting empty lines (prevents code crash when there is empty lines between
    {
        Ifelseelif = 0;
        $$ = strdup("");
    }
    ;

If_else_elif:
    IF Condition COLON
    {
        ifloop = 1;
        string temp = "if" + string($2);
        $$ = strdup(temp.c_str());
    }
    |
    ELSE COLON
    {
        ifloop = 0;
        string temp = "else";
        $$ = strdup(temp.c_str());

        if(ifloopcount == 0){
            cout<<"\relse without if in line "<<linenum<<endl;
            return 0;
        }
    }
    |
    ELIF Condition COLON
    {

        string temp = "else if " + string($2);
        $$ = strdup(temp.c_str());
        if(ifloopcount == 0)
        {
            cout<<"\relse without if in line "<<linenum<<endl;
            return 0;
        }
    }
    ;

    

Condition: 
    assign COMPARISON assign
    {
        if(((integer == 0)&&(flo == 0)&&(str == 1))|((integer == 1)&&(str == 0))|((flo == 1)&&(str == 0)))
        {
            string temp = "( "+ string($1)+ " " + string($2) + " " + string($3) + " )";
            $$ = strdup(temp.c_str());
        }
        else
        {
            cout<<"\rcomparison type mismatch in line "<<linenum<<endl;
            return 0;
        }
        str = 0;
        flo = 0;
        integer = 0;
    }
    ;

assignment:
    VAR EQUAL assign
    {
        if(flo == 1){
            for(int i = 0; i < variable_float.size();i++)
            {
                if(variable_float[i] == $1)
                {
                    alreadyin = 1;
                }
            }
            if(alreadyin != 1){
                variable_float.push_back(string($1));
            }
            string temp = string($1)+"_flt" + " = " + string($3)+ ";";
            alreadyin = 0;
            $$ = strdup(temp.c_str());
        }
        
        else if(integer == 1){
            for(int i = 0; i < variable_int.size();i++)
            {
                if(variable_int[i] == $1)
                {
                    alreadyin = 1;
                }
            }
            if(alreadyin != 1){
                variable_int.push_back(string($1));
            }
            string temp = string($1)+"_int" + " = " + string($3)+ ";";
            alreadyin = 0;
            $$ = strdup(temp.c_str());
        }
        
        if(str == 1){
            for(int i = 0; i < variable_string.size();i++)
            {
                if(variable_string[i] == $1)
                {
                    alreadyin = 1;
                }
            }
            if(alreadyin != 1){
                variable_string.push_back(string($1));
            }
            string temp = string($1)+"_str" + " = " + string($3)+";";
            alreadyin = 0;
            $$ = strdup(temp.c_str());
        }
        
        str = 0;
        flo = 0;
        integer = 0;
    }
    ;

assign:
    VAR
    {
        for(int i = 0; i < variable_int.size() ; i++ )
        {
            if(variable_int[i] == $1)
            {
                string temp = string($1)+"_int";
                $$ = strdup(temp.c_str());
                integer = 1;
            }
        }
        for(int i = 0; i < variable_float.size() ; i++ )
        {
            if(variable_float[i] == $1)
            {
                string temp = string($1)+"_flt";
                $$ = strdup(temp.c_str());
                flo = 1;
            }
        }
        for(int i = 0; i < variable_string.size() ; i++ )
        {
            if(variable_string[i] == $1)
            {
                string temp = string($1)+"_str";
                $$ = strdup(temp.c_str());
                str = 1;
            }
        }
    }
    |
    INT
    {
		integer = 1;
        $$ = strdup($1);
    }
    |
    STRING
    {
		str = 1;
        $$ = strdup($1);
    }
    |
    FLOAT
    {
        
		flo = 1;
        integer = 0;
        $$ = strdup($1);
    }
    |
    assign OP assign
    {
        string temp = string($1) + " " +string($2) + " " +string($3);
        $$ = strdup(temp.c_str());
        if((str == 1)&&((integer == 1)|(flo == 1))){
            cout<<"\rtype mismatch in line "<<linenum<<endl;
            return 0;
        }
    }

%%
void yyerror(string s){
	cerr<<"\rError..."<<endl;
    exit(1);
}
int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
    /* Call the lexer, then quit. */
    yyin=fopen(argv[1],"r");
    yyparse();
    fclose(yyin);
    return 0;
}

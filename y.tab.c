/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "project.y"

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

#line 33 "project.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
	int value;
	char * str;
	int tab;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 65 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define EQUAL 257
#define IF 258
#define ELSE 259
#define ELIF 260
#define COLON 261
#define NWLINE 262
#define VAR 263
#define INT 264
#define STRING 265
#define OP 266
#define FLOAT 267
#define COMPARISON 268
#define TAB 269
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    2,    2,    2,    6,    6,    6,
    5,    3,    4,    4,    4,    4,    4,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    3,    1,    1,    0,    3,    2,    3,
    3,    3,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    2,    5,    6,
   13,   14,   15,   16,    0,    0,    9,    0,    0,    3,
    0,    0,    0,    8,   10,    0,    4,    0,    0,
};
static const YYINT yydgoto[] = {                          6,
    7,    8,    9,   15,   16,   10,
};
static const YYINT yysindex[] = {                      -254,
 -246, -261, -246, -250, -247,    0, -248,    0,    0,    0,
    0,    0,    0,    0, -258, -241,    0, -239, -246,    0,
 -254, -246, -246,    0,    0, -242,    0, -242, -242,
};
static const YYINT yyrindex[] = {                         2,
    0,    0,    0,    0,    2,    0,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,    0,    0,    0,    0,    3,    0,    1, -233,
};
static const YYINT yygindex[] = {                         0,
    8,   26,    0,    4,   27,    0,
};
#define YYTABLESIZE 269
static const YYINT yytable[] = {                         17,
   17,    7,   12,    1,    2,    3,   19,   22,    4,   23,
    1,    2,    3,   21,    5,    4,   11,   12,   13,   24,
   14,   25,   26,   22,    1,   28,   29,   11,   27,   18,
   20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   17,   17,    7,   12,    0,    0,    0,   17,
};
static const YYINT yycheck[] = {                        261,
    0,    0,    0,  258,  259,  260,  257,  266,  263,  268,
  258,  259,  260,  262,  269,  263,  263,  264,  265,  261,
  267,  261,   19,  266,    0,   22,   23,  261,   21,    3,
    5,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  261,  262,  262,  262,   -1,   -1,   -1,  268,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 278
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"EQUAL","IF","ELSE","ELIF",
"COLON","NWLINE","VAR","INT","STRING","OP","FLOAT","COMPARISON","TAB",0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : body",
"body : statements",
"statements : statement",
"statements : TAB statement",
"statements : statements NWLINE statements",
"statement : assignment",
"statement : If_else_elif",
"statement :",
"If_else_elif : IF Condition COLON",
"If_else_elif : ELSE COLON",
"If_else_elif : ELIF Condition COLON",
"Condition : assign COMPARISON assign",
"assignment : VAR EQUAL assign",
"assign : VAR",
"assign : INT",
"assign : STRING",
"assign : FLOAT",
"assign : assign OP assign",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 492 "project.y"

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
#line 294 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 52 "project.y"
	{
        /*for empty if else elif block error*/
        string lasttemp = string(yystack.l_mark[0].str);
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
        
        /*for elif after else error*/
        
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

        cout <<"\n"<< yystack.l_mark[0].str << endl;
        cout<<"\n}\n";
    }
break;
case 2:
#line 205 "project.y"
	{
        string finalline;
        if(ifloopcount > 0)
        {
            string parclose;
            for(int i = 1; i < ifloopcount; i++)
            {
                parclose = parclose + "\t";
            }
            string temp =  parclose + "\t}\n" +string(yystack.l_mark[0].str);
            yystack.l_mark[0].str = strdup(temp.c_str());
            ifloopcount = 0;
        }

        if(Ifelseelif == 1)
        {
            ifloopcount += 1;
            ifloop = 1;
            string temp = string(yystack.l_mark[0].str)+"\n\t{";
            yystack.l_mark[0].str = strdup(temp.c_str());
        }
        else{
            ifloop = 0;
        }
        finalline = string(yystack.l_mark[0].str);
        yyval.str = strdup(finalline.c_str());
    }
break;
case 3:
#line 234 "project.y"
	{
        int iftabcount = 0;
        string temp1;
        for(int i = 0; i< yystack.l_mark[-1].tab ; i++)
        {
            temp1 = temp1 + "\t";
            iftabcount = iftabcount + 1;
        }
        string temp = temp1 + string(yystack.l_mark[0].str);
        if((ifloop == 1)&&(ifloopcount == yystack.l_mark[-1].tab))
        {
            ifloop = 0;
        }
        if (ifloop == 1)
        {
            cout<<"\rtab inconsistency in line "<<linenum<<endl;
            return 0;
        }
        else if (yystack.l_mark[-1].tab > ifloopcount)
        {
            cout<<"\rtab inconsistency in line "<<linenum<<endl;
            return 0;
        }
        else if (yystack.l_mark[-1].tab < ifloopcount)
        {
            string parclose;
            for(int i = 0; i < ifloopcount - yystack.l_mark[-1].tab ; i++)
            {
                for(int k = 1; k < ifloopcount - i;k++)
                {
                    parclose = parclose + "\t";
                }
                parclose = parclose + "\t}\n";
            }
            temp = parclose + temp;
            ifloopcount = yystack.l_mark[-1].tab;
        }
        if(Ifelseelif == 1)
        {
            ifloopcount = ifloopcount + 1;
            ifloop = 1;
            string temp4 ="\n";
            for(int i = 0; i < yystack.l_mark[-1].tab; i++)
            {
                temp4 = temp4 + "\t";
            }
            temp4 = temp4 + "\t{";
            temp =temp + temp4; 
        }
        yyval.str = strdup(temp.c_str());
    }
break;
case 4:
#line 287 "project.y"
	{
        if(string(yystack.l_mark[0].str)!="\n")
        {
            string temp = string(yystack.l_mark[-2].str) + "\n" + string(yystack.l_mark[0].str);
            yyval.str = strdup(temp.c_str());
        }
    }
break;
case 5:
#line 298 "project.y"
	{
        Ifelseelif = 0;
        string temp = "\t"+string(yystack.l_mark[0].str);
        yyval.str = strdup(temp.c_str());
    }
break;
case 6:
#line 305 "project.y"
	{
        /*indicates that the line is if or else or elif*/
        Ifelseelif = 1;
        string temp = "\t"+string(yystack.l_mark[0].str);
        yyval.str = strdup(temp.c_str());
    }
break;
case 7:
#line 313 "project.y"
	{
        Ifelseelif = 0;
        yyval.str = strdup("");
    }
break;
case 8:
#line 321 "project.y"
	{
        ifloop = 1;
        string temp = "if" + string(yystack.l_mark[-1].str);
        yyval.str = strdup(temp.c_str());
    }
break;
case 9:
#line 328 "project.y"
	{
        ifloop = 0;
        string temp = "else";
        yyval.str = strdup(temp.c_str());

        if(ifloopcount == 0){
            cout<<"\relse without if in line "<<linenum<<endl;
            return 0;
        }
    }
break;
case 10:
#line 340 "project.y"
	{

        string temp = "else if " + string(yystack.l_mark[-1].str);
        yyval.str = strdup(temp.c_str());
        if(ifloopcount == 0)
        {
            cout<<"\relse without if in line "<<linenum<<endl;
            return 0;
        }
    }
break;
case 11:
#line 356 "project.y"
	{
        if(((integer == 0)&&(flo == 0)&&(str == 1))|((integer == 1)&&(str == 0))|((flo == 1)&&(str == 0)))
        {
            string temp = "( "+ string(yystack.l_mark[-2].str)+ " " + string(yystack.l_mark[-1].str) + " " + string(yystack.l_mark[0].str) + " )";
            yyval.str = strdup(temp.c_str());
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
break;
case 12:
#line 375 "project.y"
	{
        if(flo == 1){
            for(int i = 0; i < variable_float.size();i++)
            {
                if(variable_float[i] == yystack.l_mark[-2].str)
                {
                    alreadyin = 1;
                }
            }
            if(alreadyin != 1){
                variable_float.push_back(string(yystack.l_mark[-2].str));
            }
            string temp = string(yystack.l_mark[-2].str)+"_flt" + " = " + string(yystack.l_mark[0].str)+ ";";
            alreadyin = 0;
            yyval.str = strdup(temp.c_str());
        }
        
        else if(integer == 1){
            for(int i = 0; i < variable_int.size();i++)
            {
                if(variable_int[i] == yystack.l_mark[-2].str)
                {
                    alreadyin = 1;
                }
            }
            if(alreadyin != 1){
                variable_int.push_back(string(yystack.l_mark[-2].str));
            }
            string temp = string(yystack.l_mark[-2].str)+"_int" + " = " + string(yystack.l_mark[0].str)+ ";";
            alreadyin = 0;
            yyval.str = strdup(temp.c_str());
        }
        
        if(str == 1){
            for(int i = 0; i < variable_string.size();i++)
            {
                if(variable_string[i] == yystack.l_mark[-2].str)
                {
                    alreadyin = 1;
                }
            }
            if(alreadyin != 1){
                variable_string.push_back(string(yystack.l_mark[-2].str));
            }
            string temp = string(yystack.l_mark[-2].str)+"_str" + " = " + string(yystack.l_mark[0].str)+";";
            alreadyin = 0;
            yyval.str = strdup(temp.c_str());
        }
        
        str = 0;
        flo = 0;
        integer = 0;
    }
break;
case 13:
#line 432 "project.y"
	{
        for(int i = 0; i < variable_int.size() ; i++ )
        {
            if(variable_int[i] == yystack.l_mark[0].str)
            {
                string temp = string(yystack.l_mark[0].str)+"_int";
                yyval.str = strdup(temp.c_str());
                integer = 1;
            }
        }
        for(int i = 0; i < variable_float.size() ; i++ )
        {
            if(variable_float[i] == yystack.l_mark[0].str)
            {
                string temp = string(yystack.l_mark[0].str)+"_flt";
                yyval.str = strdup(temp.c_str());
                flo = 1;
            }
        }
        for(int i = 0; i < variable_string.size() ; i++ )
        {
            if(variable_string[i] == yystack.l_mark[0].str)
            {
                string temp = string(yystack.l_mark[0].str)+"_str";
                yyval.str = strdup(temp.c_str());
                str = 1;
            }
        }
    }
break;
case 14:
#line 463 "project.y"
	{
		integer = 1;
        yyval.str = strdup(yystack.l_mark[0].str);
    }
break;
case 15:
#line 469 "project.y"
	{
		str = 1;
        yyval.str = strdup(yystack.l_mark[0].str);
    }
break;
case 16:
#line 475 "project.y"
	{
        
		flo = 1;
        integer = 0;
        yyval.str = strdup(yystack.l_mark[0].str);
    }
break;
case 17:
#line 483 "project.y"
	{
        string temp = string(yystack.l_mark[-2].str) + " " +string(yystack.l_mark[-1].str) + " " +string(yystack.l_mark[0].str);
        yyval.str = strdup(temp.c_str());
        if((str == 1)&&((integer == 1)|(flo == 1))){
            cout<<"\rtype mismatch in line "<<linenum<<endl;
            return 0;
        }
    }
break;
#line 940 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

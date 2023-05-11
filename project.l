digit	[0-9]
letter	[A-Za-z]
%{
#include "y.tab.h"
int tabnum = 0;
unsigned int linenum=1;
%}
%%
"elif" {  return ELIF ;}
"if" { return IF ;}
"else" { return ELSE;}
\n {linenum++; return 	NWLINE;}
({digit}+"."{digit}+)|("-"{digit}+"."{digit}+) { yylval.str = strdup(yytext);return FLOAT;}
("-"{digit}+)|({digit}+)  { yylval.str = strdup(yytext);return INT;}
\"({letter}|{digit})*\" { yylval.str = strdup(yytext); return STRING;}
{letter}({letter}|{digit})*  { yylval.str = strdup(yytext); return VAR;}
"*"|"/"|"+"|"-"  {yylval.str = strdup(yytext);return OP;}
"<"|">"|"<="|">="|"=="|"!=" {yylval.str = strdup(yytext);return COMPARISON;}
":"  return COLON;
"="  return EQUAL;

(\t|[ ]{4})+ {
    tabnum=0;
    for(int i =0;i<=strlen(yytext);i++)
        if(yytext[i]=='\t')
            tabnum++;
    yylval.tab = tabnum;
    return TAB;
} 




%%

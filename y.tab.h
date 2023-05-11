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
extern YYSTYPE yylval;

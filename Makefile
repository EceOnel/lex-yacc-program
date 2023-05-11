all:lex yacc
	g++ lex.yy.c y.tab.c -ll -o project
lex:project.l
	lex project.l
yacc:project.y
	yacc -d project.y
clean:
	rm lex.yy.c y.tab.c y.tab.h project

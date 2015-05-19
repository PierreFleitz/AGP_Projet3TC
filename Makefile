all:	logo

logo:	monProg.o tplogo.tab.c lex.yy.c
		gcc monProg.o lex.yy.c tplogo.tab.c -o logo -lm
		
monProg.o:	monProg.c
			gcc -c monProg.c -o monProg.o -lm
			
tplogo.tab.c: tplogo.y
	bison -d tplogo.y
	
lex.yy.c: tplogo.l
	flex tplogo.l
	
clean:
	rm -rf *.o rm -rf *.yy.c rm -rf .tab.c rm -rf *.tab.h rm -rf *.tab.c 

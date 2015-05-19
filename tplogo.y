/***********************************************************************
				       
						DEFINITIONS	       
 			               
***********************************************************************/

%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"monProg.h"

void yyerror(const char *str)
{
fprintf(stdout, "error: %s \n", str);
}

int yywrap()
{
return 1;
}

%}

// symbole des terminaux

%token VALUE FORWARD RIGHT LEFT REPEAT CIRCLE SQUARE

// type de yylval

%union {
	NODE* NODE_TYPE;
	int val;
};

// type des terminaux

%type <val> VALUE;
%type <NODE_TYPE> FORWARD RIGHT LEFT REPEAT CIRCLE SQUARE

// type des non-terminaux

%type <NODE_TYPE> FILE PROG INST

%%

/***********************************************************************
			       	   
							GRAMMAIRE	       
							ANNOTEE		       
 			               
***********************************************************************/

FILE : PROG
{
root = $1;
}
PROG : INST
{
$$ = $1;
}
|PROG INST
{
$$=addNode($1,$2);
}

INST : FORWARD VALUE
{
$$=newNode(1,$2,NULL);
}
|LEFT VALUE
{
$$=newNode(3,$2,NULL);
}
|RIGHT VALUE
{
$$=newNode(4,$2,NULL);
}
|REPEAT VALUE '[' PROG ']'
{
$$=newNode(2,$2,$4);
}
|CIRCLE VALUE
{
$$=newNode(5,$2,NULL);
}
|SQUARE VALUE
{
$$=newNode(6,$2,NULL);
}

%%

/***********************************************************************
				           
							FONCTION	       
							MAIN		       
 			              
***********************************************************************/

int main(){

yyparse();
printProgram(root);
generatSVG(root,fichier,origine);
freeProgram(root);
return 0;

}

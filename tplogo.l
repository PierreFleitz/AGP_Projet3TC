%{
#include<stdio.h>
#include<stdlib.h>
#include"monProg.h"
#include"tplogo.tab.h"

%}

%%

[1-9][0-9]* { yylval.val=atoi(yytext); return VALUE;}
"["	{return '[';}
"]"	{return ']';}
"REPEAT"	{return REPEAT;}
"FORWARD"	{return FORWARD;}
"LEFT"	{return LEFT;}
"RIGHT"	{return RIGHT;}
"CIRCLE"	{return CIRCLE;}
"SQUARE"	{return SQUARE;}
\n /*ignore linebreak */;
[ \t]+ /* ignore whitespace */;

%%

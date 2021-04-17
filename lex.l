%{
	#include "parser.tab.h"
%}

%%

"ADD" {return ADD;}
"Add" {return add;}
"SUBTRACT" {return SUBTRACT;}
"Subtract" {return subtract;}
"MULTIPLY" {return MULTIPLY;}
"Multiply" {return multiply;}
"DIVIDE" {return DIVIDE;}
"Divide" {return divide;}
"LEFT" {return LEFT;}
"Left" {return left;}
"RIGHT" {return RIGHT;}
"Right" {return right;}
"UP" {return UP;}
"Up" {return up;}
"DOWN" {return DOWN;}
"Down" {return down;}
"ASSIGN" {return ASSIGN;}
"TO" {return TO;}
"VAR" {return VAR;}
"IS" {return IS;}
"VALUE" {return VALUE;}
"IN" {return IN;}
"." {return TERMINATOR;}
[-0-9]+ {yylval.number = atoi(yytext); return NUMBER;}
[a-zA-Z]+ {sscanf(yytext, "%s", yylval.string); return VARNAME;}
"," {return SEPARATOR;}
[ \t] {}
\n {return EOL;}
. ;

%%

int yywrap(){return 0;}


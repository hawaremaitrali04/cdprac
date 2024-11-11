%{
#include "cal.tab.h" 
#include <stdlib.h>
%}

%%

[0-9]+   { yylval = atoi(yytext); return NUMBER; } // Match numbers and return NUMBER token
[ \t]+   ; // Ignore whitespace
\n       { return EOL; } // Handle newline as end of line
"+"      { return '+'; } // Match + operator
"-"      { return '-'; } // Match - operator
"*"      { return '*'; } // Match * operator
"/"      { return '/'; } // Match / operator

.        { printf("Unknown character: %s\n", yytext); } // Catch-all for unknown characters

%%

int yywrap() {
    return 1;
}



//syntax
//flex cal.l

//bison -d cal.y

//gcc lex.yy.c cal.tab.c

//a.exe
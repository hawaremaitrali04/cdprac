%{
#include <stdio.h>
%}

%%

"//".*                    { printf("Single-line comment found: %s\n", yytext); }

"/*"([^*]*|\*+[^*/])*"*"+"/" {
    printf("Multi-line comment found: %s\n", yytext);
}

.|\n                      { /* Ignore other characters and lines */ }

%%

int main() {
    printf("Enter C code (press Ctrl+D to finish):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
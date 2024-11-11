%{
#include <stdio.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Identifier found: %s\n", yytext);
}

[ \t\n]+       { /* Ignore whitespace */ }

.              { /* Ignore other characters */ }

%%

int main() {
    printf("Enter C code (press Ctrl+D to finish):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
%{
#include <stdio.h>
%}

%%

"&&"            { printf("Logical operator found: %s\n", yytext); }
"||"            { printf("Logical operator found: %s\n", yytext); }
"!"             { printf("Logical operator found: %s\n", yytext); }

.|\n            { /* Ignore other characters and lines */ }

%%

int main() {
    printf("Enter C code (press Ctrl+D to finish):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
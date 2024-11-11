%{
#include <stdio.h>
%}

%%

"=="             { printf("Relational operator found: %s\n", yytext); }
"!="             { printf("Relational operator found: %s\n", yytext); }
"<="             { printf("Relational operator found: %s\n", yytext); }
">="             { printf("Relational operator found: %s\n", yytext); }
"<"              { printf("Relational operator found: %s\n", yytext); }
">"              { printf("Relational operator found: %s\n", yytext); }

.|\n             { /* Ignore other characters and lines */ }

%%

int main() {
    printf("Enter C code (press Ctrl+D to finish):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
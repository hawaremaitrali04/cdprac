%{
#include <stdio.h>
#include <stdlib.h>

// Declare yylex and yyerror prototypes
int yylex();
int yyerror(const char *s);
%}

%token NUMBER
%token EOL

// Set precedence and associativity for operators
%left '+' '-'
%left '*' '/'

%%

input:
    /* empty */
    | input line
    ;

line:
    EOL
    | expr EOL       { printf("Result: %d\n", $1); }
    ;

expr:
    NUMBER            { $$ = $1; printf("Recognized NUMBER: %d\n", $1); }
    | expr '+' expr   { $$ = $1 + $3; printf("Adding %d and %d\n", $1, $3); }
    | expr '-' expr   { $$ = $1 - $3; printf("Subtracting %d and %d\n", $1, $3); }
    | expr '*' expr   { $$ = $1 * $3; printf("Multiplying %d and %d\n", $1, $3); }
    | expr '/' expr   { 
                        if ($3 == 0) {
                            printf("Error: Division by zero\n");
                            exit(1);
                        } else {
                            $$ = $1 / $3;
                            printf("Dividing %d by %d\n", $1, $3);
                        }
                      }
    ;
%%

int main() {
    printf("Enter expressions:\n");
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}

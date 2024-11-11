%{
#include <stdio.h>

int char_count = 0;
int line_count = 0;
int tab_count = 0;
int word_count = 0;
int number_count = 0;
int special_symbol_count = 0;
int space_count = 0;
%}

%%

\n              { line_count++; char_count++; }
\t              { tab_count++; char_count++; }
[ ]             { space_count++; char_count++; }
[0-9]+          { number_count++; char_count += yyleng; }
[a-zA-Z]+       { word_count++; char_count += yyleng; }
[^a-zA-Z0-9\t\n ] { special_symbol_count++; char_count++; }

%%

int main() {
    printf("Enter text (press Ctrl+D to finish):\n");
    yylex();
    printf("\nResults:\n");
    printf("Characters: %d\n", char_count);
    printf("Lines: %d\n", line_count);
    printf("Tabs: %d\n", tab_count);
    printf("Words: %d\n", word_count);
    printf("Numbers: %d\n", number_count);
    printf("Special Symbols: %d\n", special_symbol_count);
    printf("Spaces: %d\n", space_count);
    return 0;
}

int yywrap() {
    return 1;
}
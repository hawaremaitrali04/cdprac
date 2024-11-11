%{
#include <stdio.h>
#include <string.h>

int vowel_count = 0;
%}

%%

[aeiouAEIOU][a-zA-Z]* {
    printf("String starting with vowel: %s\n", yytext);
    vowel_count++;
}

[ \t]+ {}

\n {}

[^aeiouAEIOU \t\n]+ {}

%%

int yywrap() {
    return 1;
}

int main(int argc, char **argv) {
    yylex();
    printf("Total strings starting with vowels: %d\n", vowel_count);
    return 0;
}

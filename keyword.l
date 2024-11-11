%{
#include <stdio.h>
%}

%%

"auto"              { printf("Keyword found: %s\n", yytext); }
"break"             { printf("Keyword found: %s\n", yytext); }
"case"              { printf("Keyword found: %s\n", yytext); }
"char"              { printf("Keyword found: %s\n", yytext); }
"const"             { printf("Keyword found: %s\n", yytext); }
"continue"          { printf("Keyword found: %s\n", yytext); }
"default"           { printf("Keyword found: %s\n", yytext); }
"do"                { printf("Keyword found: %s\n", yytext); }
"double"            { printf("Keyword found: %s\n", yytext); }
"else"              { printf("Keyword found: %s\n", yytext); }
"enum"              { printf("Keyword found: %s\n", yytext); }
"extern"            { printf("Keyword found: %s\n", yytext); }
"float"             { printf("Keyword found: %s\n", yytext); }
"for"               { printf("Keyword found: %s\n", yytext); }
"goto"              { printf("Keyword found: %s\n", yytext); }
"if"                { printf("Keyword found: %s\n", yytext); }
"inline"            { printf("Keyword found: %s\n", yytext); }
"int"               { printf("Keyword found: %s\n", yytext); }
"long"              { printf("Keyword found: %s\n", yytext); }
"register"          { printf("Keyword found: %s\n", yytext); }
"restrict"          { printf("Keyword found: %s\n", yytext); }
"return"            { printf("Keyword found: %s\n", yytext); }
"short"             { printf("Keyword found: %s\n", yytext); }
"signed"            { printf("Keyword found: %s\n", yytext); }
"sizeof"            { printf("Keyword found: %s\n", yytext); }
"static"            { printf("Keyword found: %s\n", yytext); }
"struct"            { printf("Keyword found: %s\n", yytext); }
"switch"            { printf("Keyword found: %s\n", yytext); }
"typedef"           { printf("Keyword found: %s\n", yytext); }
"union"             { printf("Keyword found: %s\n", yytext); }
"unsigned"          { printf("Keyword found: %s\n", yytext); }
"void"              { printf("Keyword found: %s\n", yytext); }
"volatile"          { printf("Keyword found: %s\n", yytext); }
"while"             { printf("Keyword found: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* { /* Ignore identifiers or other words */ }

[ \t\n]+               { /* Ignore whitespace */ }

.                      { /* Ignore other characters */ }

%%

int main() {
    printf("Enter C code (press Ctrl+D to finish):\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
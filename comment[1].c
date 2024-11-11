//comment.c

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

void detect_comments(FILE *input) {
    char ch, next_ch;
    while ((ch = fgetc(input)) != EOF) {
        // Check for single-line comments
        if (ch == '/' && (next_ch = fgetc(input)) == '/') {
            printf("Single-line comment found: //");
            while ((ch = fgetc(input)) != EOF && ch != '\n') {
                putchar(ch);
            }
            putchar('\n');
        }
        // Check for multi-line comments
        else if (ch == '/' && next_ch == '*') {
            printf("Multi-line comment found: /*");
            while ((ch = fgetc(input)) != EOF) {
                putchar(ch);
                if (ch == '*' && (next_ch = fgetc(input)) == '/') {
                    putchar('/');
                    putchar('\n');
                    break;
                }
                ungetc(next_ch, input);
            }
        }
    }
}

int main() {
    printf("Enter C code (press Ctrl+D to finish on Unix, Ctrl+Z on Windows):\n");
    detect_comments(stdin);
    return 0;
}





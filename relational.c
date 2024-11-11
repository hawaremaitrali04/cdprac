//relational.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 100

// Function to check and print relational operators
void detect_relational_operators(FILE *input) {
    char ch, next_ch, token[MAX_TOKEN_SIZE];
    int i = 0;

    while ((ch = fgetc(input)) != EOF) {
        // Collect characters into a token
        token[i++] = ch;

        // Check for relational operators
        if (ch == '=') {
            next_ch = fgetc(input);
            if (next_ch == '=') {
                token[i++] = next_ch;
                token[i] = '\0';
                printf("Relational operator found: %s\n", token);
                i = 0;
            } else {
                ungetc(next_ch, input);  // If not '==', push the character back
            }
        } else if (ch == '!') {
            next_ch = fgetc(input);
            if (next_ch == '=') {
                token[i++] = next_ch;
                token[i] = '\0';
                printf("Relational operator found: %s\n", token);
                i = 0;
            } else {
                ungetc(next_ch, input);  // If not '!=', push the character back
            }
        } else if (ch == '<' || ch == '>') {
            next_ch = fgetc(input);
            if ((ch == '<' && next_ch == '=') || (ch == '>' && next_ch == '=')) {
                token[i++] = next_ch;
                token[i] = '\0';
                printf("Relational operator found: %s\n", token);
                i = 0;
            } else {
                ungetc(next_ch, input);  // If not '<=' or '>=', push back
                token[i] = '\0';
                printf("Relational operator found: %s\n", token);
                i = 0;
            }
        }
        // Ignore other characters and lines
        else if (isspace(ch)) {
            if (i > 0) {
                token[i] = '\0';
                i = 0;
            }
        }
    }
}

int main() {
    printf("Enter C code (press Ctrl+D to finish):\n");
    detect_relational_operators(stdin);
    return 0;
}

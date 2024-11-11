//logical.c

#include <stdio.h>

#define MAX_TOKEN_SIZE 100

// Function to detect logical operators
void detect_logical_operators(FILE *input) {
    char ch, next_ch, token[MAX_TOKEN_SIZE];
    int i = 0;

    while ((ch = fgetc(input)) != EOF) {
        // Collect characters into a token
        token[i++] = ch;

        // Check for logical operators
        if (ch == '&') {
            next_ch = fgetc(input);
            if (next_ch == '&') {
                token[i++] = next_ch;
                token[i] = '\0';
                printf("Logical operator found: %s\n", token);
                i = 0;
            } else {
                ungetc(next_ch, input);  // If not '&&', push the character back
            }
        } else if (ch == '|') {
            next_ch = fgetc(input);
            if (next_ch == '|') {
                token[i++] = next_ch;
                token[i] = '\0';
                printf("Logical operator found: %s\n", token);
                i = 0;
            } else {
                ungetc(next_ch, input);  // If not '||', push the character back
            }
        } else if (ch == '!') {
            token[i] = '\0';
            printf("Logical operator found: %s\n", token);
            i = 0;
        }
        // Ignore other characters and lines
        else if (ch == '\n' || ch == ' ' || ch == '\t') {
            if (i > 0) {
                token[i] = '\0';
                i = 0;
            }
        }
    }
}

int main() {
    printf("Enter C code (press Ctrl+D to finish on Unix, Ctrl+Z on Windows):\n");
    detect_logical_operators(stdin);
    return 0;
}

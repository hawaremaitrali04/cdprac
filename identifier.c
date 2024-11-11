//identifier.c

#include <stdio.h>
#include <ctype.h>

int is_identifier_start(char ch) {
    // Checks if the character is a valid starting character for an identifier
    return (isalpha(ch) || ch == '_');
}

int is_identifier_part(char ch) {
    // Checks if the character is a valid part of an identifier
    return (isalnum(ch) || ch == '_');
}

int main() {
    char ch;
    char buffer[100]; // Buffer to store identifiers
    int index = 0;

    printf("Enter C code (press Ctrl+D to finish on Unix, Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        // Check for the start of an identifier
        if (is_identifier_start(ch)) {
            buffer[index++] = ch;
            while ((ch = getchar()) != EOF && is_identifier_part(ch)) {
                buffer[index++] = ch;
            }
            buffer[index] = '\0'; // Null-terminate the string
            printf("Identifier found: %s\n", buffer);
            index = 0; // Reset index for the next identifier

            // If the loop was exited because of EOF or a non-identifier character, reprocess it
            if (ch == EOF) break;
        }
    }

    return 0;
}

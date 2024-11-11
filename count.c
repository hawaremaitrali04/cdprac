//count.c

#include <stdio.h>
#include <ctype.h>

int main() {
    int char_count = 0;
    int line_count = 0;
    int tab_count = 0;
    int word_count = 0;
    int number_count = 0;
    int special_symbol_count = 0;
    int space_count = 0;
    int in_word = 0;
    char ch;

    printf("Enter text (Ctrl+D to end input on Unix, Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        char_count++;

        // Check for newline
        if (ch == '\n') {
            line_count++;
        }

        // Check for tab
        if (ch == '\t') {
            tab_count++;
        }

        // Check for spaces
        if (ch == ' ') {
            space_count++;
        }

        // Check if character is part of a word
        if (isalpha(ch)) {
            if (!in_word) {
                word_count++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }

        // Check for numbers
        if (isdigit(ch)) {
            number_count++;
        }

        // Check for special symbols
        if (!isalnum(ch) && !isspace(ch)) {
            special_symbol_count++;
        }
    }

    // Print results
    printf("\nTotal Characters: %d\n", char_count);
    printf("Total Lines: %d\n", line_count);
    printf("Total Tabs: %d\n", tab_count);
    printf("Total Words: %d\n", word_count);
    printf("Total Numbers: %d\n", number_count);
    printf("Total Special Symbols: %d\n", special_symbol_count);
    printf("Total Spaces: %d\n", space_count);

    return 0;
}

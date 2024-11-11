//keyword.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
    "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

// Function to check if a word is a C keyword
int is_keyword(const char *word) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // Keyword found
        }
    }
    return 0; // Not a keyword
}

int main() {
    char word[100]; // Buffer to store each word

    printf("Enter C code (press Ctrl+D to finish on Unix, Ctrl+Z on Windows):\n");

    while (scanf("%99s", word) != EOF) {
        // Check if the scanned word is a keyword
        if (is_keyword(word)) {
            printf("Keyword found: %s\n", word);
        }
    }

    return 0;
}

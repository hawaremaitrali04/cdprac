//vowel.c

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_vowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main() {
    char word[100]; // Buffer to store each word
    int vowel_count = 0;

    printf("Enter text (Ctrl+D to end input on Unix, Ctrl+Z on Windows):\n");

    while (scanf("%s", word) != EOF) {
        // Check if the first character of the word is a vowel
        if (is_vowel(word[0])) {
            printf("String starting with vowel: %s\n", word);
            vowel_count++;
        }
    }

    printf("\nTotal strings starting with vowels: %d\n", vowel_count);

    return 0;
}

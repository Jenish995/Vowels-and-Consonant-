#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_vowels_consonants(const char *paragraph, int *vowel_count, int *consonant_count) {
    *vowel_count = 0;
    *consonant_count = 0;
    
    while (*paragraph) {
        char ch = tolower(*paragraph);
        if (ch >= 'a' && ch <= 'z') {
            if (strchr("aeiou", ch)) {
                (*vowel_count)++;
            } else {
                (*consonant_count)++;
            }
        }
        paragraph++;
    }
}

int main() {
    char paragraph[1000];
    int vowels = 0, consonants = 0;
    
    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Remove trailing newline, if present
    paragraph[strcspn(paragraph, "\n")] = '\0';

    if (strlen(paragraph) == 0) {
        printf("No input provided.\n");
        return 1;
    }

    count_vowels_consonants(paragraph, &vowels, &consonants);
    
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50
#define MAX_PARAGRAPH_LEN 1000

// Structure to store word and its frequency
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFreq;

// Function to convert string to lowercase for case-insensitive comparison
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[MAX_PARAGRAPH_LEN];
    WordFreq words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Remove trailing newline if any
    paragraph[strcspn(paragraph, "\n")] = '\0';

    // Tokenize paragraph into words based on space and punctuation
    char *delimiters = " ,.!?;:\n\t\"\'()-";
    char *token = strtok(paragraph, delimiters);

    while (token != NULL) {
        toLowerCase(token);  // Make word lowercase

        // Check if word already exists in words array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add new word
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, delimiters);
    }

    // Print the word frequencies
    printf("\nWord frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s : %d\n", words[i].word, words[i].count);
    }

    return 0;
}

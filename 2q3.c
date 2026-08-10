#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 50

int main() {
    char paragraph[1000];
    char words[MAX_WORDS][MAX_LEN];
    int counts[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t.,!?;:");
    while (token != NULL) {
        // Convert to lowercase for consistent counting
        char cleanWord[MAX_LEN];
        int k = 0;
        for (int i = 0; token[i]; i++) {
            if (isalpha(token[i]) || isdigit(token[i])) {
                cleanWord[k++] = tolower(token[i]);
            }
        }
        cleanWord[k] = '\0';

        if (strlen(cleanWord) > 0) {
            // Check if word already exists
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(words[i], cleanWord) == 0) {
                    counts[i]++;
                    found = 1;
                    break;
                }
            }
            if (!found && wordCount < MAX_WORDS) {
                strcpy(words[wordCount], cleanWord);
                counts[wordCount] = 1;
                wordCount++;
            }
        }
        token = strtok(NULL, " \n\t.,!?;:");
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], counts[i]);
    }

    return 0;
}

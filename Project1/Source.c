#include <stdio.h>
#include <string.h>

// Function to swap two characters
void swap(char* x, char* y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate anagrams using recursion
void generateAnagrams(char* word, int start, int end, int* count) {
    int i;
    if (start == end) {
        (*count)++;
        printf("%s\n", word);
    }
    else {
        for (i = start; i <= end; i++) {
            int isDuplicate = 0;
            // Check if swapping with the same character occurs
            for (int j = start; j < i; j++) {
                if (word[j] == word[i]) {
                    isDuplicate = 1;
                    break;
                }
            }
            if (isDuplicate)
                continue;

            swap((word + start), (word + i));
            generateAnagrams(word, start + 1, end, count);
            swap((word + start), (word + i)); // Restore the initial state
        }
    }
}

int main() {
    char word[15];
    int count = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    int length = strlen(word);

    printf("Possible anagrams:\n");
    generateAnagrams(word, 0, length - 1, &count);

    printf("Number of anagrams: %d\n", count);

    return 0;
}

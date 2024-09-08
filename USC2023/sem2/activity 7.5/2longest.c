#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char strings[5][MAX_STRING_LENGTH];
    int longestIndex = 0;

    for (int i = 0; i < 5; i++) {
        printf("Enter string %d: ", i + 1);
        fgets(strings[i], sizeof(strings[i]), stdin);
        size_t len = strlen(strings[i]);
        if (len > 0 && strings[i][len - 1] == '\n') {
            strings[i][len - 1] = '\0';
        }
        if (strlen(strings[i]) > strlen(strings[longestIndex])) {
            longestIndex = i;
        }
    }
    printf("\nThe longest string is: %s\n", strings[longestIndex]);

    return 0;
}

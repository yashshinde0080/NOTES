#include <stdio.h>
#include <string.h>
/*
Design, develop and implement a Program in C for the following operations on Strings
a.	Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
b.	Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR with REP if PAT exists in STR. Report suitable messages in case PAT does not exist in STR
Support the program with functions for each of the above operations. Don't use Built-in functions
*/

// Function prototypes
void getInput(char *str, const char *prompt);
int findAndReplace(char *str, const char *pattern, const char *replacement, char *result);

int main() {
    char str[100], pattern[20], replacement[20], result[120];
    int found;

    // Get input from the user
    getInput(str, "Enter the main string: ");
    getInput(pattern, "Enter the pattern to search: ");
    getInput(replacement, "Enter the replacement string: ");

    // Find and replace the pattern in the main string
    found = findAndReplace(str, pattern, replacement, result);

    if (!found) {
        printf("Pattern not found in the main string.\n");
    } else {
        printf("Modified string after replacement: %s\n", result);
    }

    return 0;
}

// Function to get input from the user
void getInput(char *str, const char *prompt) {
    printf("%s", prompt);
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character
}

// Function to find and replace the pattern in the main string
int findAndReplace(char *str, const char *pattern, const char *replacement, char *result) {
    int i, j, k, l, flag, found = 0;
    int strLen = strlen(str);
    int patLen = strlen(pattern);
    int repLen = strlen(replacement);

    for (i = 0, k = 0; i < strLen; i++) {
        flag = 1;

        // Check if the pattern matches the current position in the string
        for (j = 0; j < patLen; j++) {
            if (str[i + j] != pattern[j]) {
                flag = 0;
                break;
            }
        }

        if (flag) {  // If pattern matches, replace with the replacement string
            for (j = 0; j < repLen; j++, k++) {
                result[k] = replacement[j];
            }
            i += patLen - 1;  // Skip over the matched pattern
            found = 1;
        } else {
            result[k++] = str[i];  // Copy the current character to result
        }
    }

    result[k] = '\0';  // Null-terminate the result string
    return found;
}

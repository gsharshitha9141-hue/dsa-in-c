#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to decode the string recursively
char* decodeHelper(const char* s, int* index) {
    // Allocate space for the current level's decoded result string
    // Given the constraints, a dynamically growing block or safe initial size works.
    int capacity = 1000;
    char* res = (char*)malloc(capacity * sizeof(char));
    res[0] = '\0';
    int resLen = 0;

    while (s[*index] != '\0' && s[*index] != ']') {
        if (!isdigit(s[*index])) {
            // Case 1: Standard character - append it directly
            if (resLen + 1 >= capacity) {
                capacity *= 2;
                res = (char*)realloc(res, capacity * sizeof(char));
            }
            res[resLen++] = s[*index];
            res[resLen] = '\0';
            (*index)++;
        } else {
            // Case 2: Number found - calculate the repetition count 'k'
            int k = 0;
            while (isdigit(s[*index])) {
                k = k * 10 + (s[*index] - '0');
                (*index)++;
            }

            // Skip the opening bracket '['
            (*index)++; 

            // Recursively decode the nested structure inside the brackets
            char* nestedStr = decodeHelper(s, index);

            // Skip the closing bracket ']'
            (*index)++; 

            // Repeat the decoded nested string 'k' times and append to res
            int nestedLen = strlen(nestedStr);
            int neededSpace = resLen + (k * nestedLen) + 1;
            if (neededSpace > capacity) {
                capacity = neededSpace * 2;
                res = (char*)realloc(res, capacity * sizeof(char));
            }

            for (int i = 0; i < k; i++) {
                strcpy(res + resLen, nestedStr);
                resLen += nestedLen;
            }
            
            // Free the memory allocated for the sub-problem
            free(nestedStr); 
        }
    }

    return res;
}

char* decodeString(char* s) {
    int index = 0;
    return decodeHelper(s, &index);
}

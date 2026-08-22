#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int n = strlen(s);
    int left = 0, right = 0;
    int max_len = 0;

    // First Pass: Left to Right
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            max_len = MAX(max_len, 2 * right);
        } else if (right > left) {
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;

    // Second Pass: Right to Left
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            max_len = MAX(max_len, 2 * left);
        } else if (left > right) {
            left = 0;
            right = 0;
        }
    }

    return max_len;
}

int minAddToMakeValid(char* s) {
    int open_needed = 0;   // Tracks unmatched closing parentheses ')'
    int close_needed = 0;  // Tracks unmatched opening parentheses '('

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            close_needed++;
        } else { // s[i] == ')'
            if (close_needed > 0) {
                close_needed--; // Successfully matched a pair
            } else {
                open_needed++;  // Unmatched ')', requires an added '('
            }
        }
    }

    return open_needed + close_needed;
}

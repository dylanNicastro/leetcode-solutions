#include <stdbool.h>

bool canConstruct(char* s, int k) {
    int freq[26] = {0};
    int len = 0;
    while (*s != '\0') {
        freq[*s - 'a'] += 1;
        len++;
        s++;
    }
    if (len < k) return false;
    if (len == k) return true;
    int odds = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) odds++;
    }
    if (odds > k) return false;
    return true;
}
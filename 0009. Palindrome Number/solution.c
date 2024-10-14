#include <stdbool.h>
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    long int x_orig = x;
    long int x_rev = 0;
    while (1) {
        x_rev = x_rev*10 + x%10;
        x = floor(x/10);
        if (x == 0) break;
    }
    if (x_orig == x_rev) return true;
    else return false;
}
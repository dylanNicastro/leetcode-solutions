#include <cstddef>
int lengthOfLastWord(char* s) {
    char* lastword;
    char* word = strtok(s, " ");
    while (word != NULL) {
        lastword = word;
        word = strtok(NULL, " ");
    }
    return strlen(lastword);
}
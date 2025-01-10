/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int frequencies[26] = {0};
    for (int i = 0; i < words2Size; i++) {
        int currentFreq[26] = {0};
        char* wordPtr = words2[i];
        while (*wordPtr != '\0') {
            currentFreq[*wordPtr - 'a']++;
            wordPtr++;
        }
        for (int j = 0; j < 26; j++) {
            if (currentFreq[j] > frequencies[j]) frequencies[j] = currentFreq[j];
        }
    }

    char** returnWords = malloc(words1Size*sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < words1Size; i++) {
        int currentFreq[26] = {0};
        char* wordPtr = words1[i];
        while (*wordPtr != '\0') {
            currentFreq[*wordPtr - 'a']++;
            wordPtr++; 
        }
        int flag = 1;
        for (int j = 0; j < 26; j++) {
            if (currentFreq[j] < frequencies[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            returnWords[*returnSize] = words1[i];
            (*returnSize)++;
        }
    }

    returnWords = realloc(returnWords, (*returnSize)*sizeof(char*));
    return returnWords;
}
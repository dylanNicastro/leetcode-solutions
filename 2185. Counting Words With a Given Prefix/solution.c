int containsPrefix(char* word, char* pref) {
    char* wordPtr = word;
    char* prefPtr = pref;
    while (*wordPtr != '\0' && *prefPtr != '\0') {
        if (*wordPtr != *prefPtr) break;
        wordPtr++;
        prefPtr++;
    }
    if (*prefPtr == '\0') return 1;
    return 0;
}

int prefixCount(char** words, int wordsSize, char* pref) {
    int count = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (containsPrefix(words[i], pref) == 1) count++;
    }
    return count;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    char* prefix = malloc(200*sizeof(char));
    int i = -1;

    do {
        i++;
        prefix[i] = strs[0][i];
        for (int count = 0; count < strsSize; count++) {
            if (!strs[count][i] || strs[count][i] != prefix[i]) {
                prefix[i] = '\0';
            }
        }
    } while (prefix[i]);
    return prefix;
}
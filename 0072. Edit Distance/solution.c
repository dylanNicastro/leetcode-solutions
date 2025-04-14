int min(int int1, int int2) {
    return ((int1 < int2) ? int1 : int2);
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) dp[i][j] = i;
            else if (i == 0) dp[i][j] = j;
            else dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
        }
    }
    return dp[m][n];
}
bool isValidSquare(char** board, int x, int y) { // coordinates of top-left box
    int numUsed[9] = {0};
    for (int i = 0; i < 9; i++) {
        char current = board[x + i/3][y + i%3];
        if (current == '.') continue;
        if (numUsed[current - '1'] == 1) return false;
        numUsed[current - '1'] = 1;
    }
    return true;
}

bool isValidRow(char** board, int rowIndex) {
    int numUsed[9] = {0};
    for (int i = 0; i < 9; i++) {
        char current = board[rowIndex][i];
        if (current == '.') continue;
        if (numUsed[current - '1'] == 1) return false;
        numUsed[current - '1'] = 1;
    }
    return true;
}

bool isValidCol(char** board, int colIndex) {
    int numUsed[9] = {0};
    for (int i = 0; i < 9; i++) {
        char current = board[i][colIndex];
        if (current == '.') continue;
        if (numUsed[current - '1'] == 1) return false;
        numUsed[current - '1'] = 1;
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        if (!isValidSquare(board, i/3 * 3, i%3 * 3)) return false;
        if (!isValidRow(board, i)) return false;
        if (!isValidCol(board, i)) return false;
    }
    return true;
}
class Solution {
public:
    bool check(int row, int col, int digit, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit + '0')
                return false;
            if (board[i][col] == digit + '0')
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] ==
                digit + '0')
                return false;
        }
        return true;
    }
    bool solver(vector<vector<char>>& board) {
        // choice
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (int d = 1; d < 10; d++) {
                        if (check(row, col, d, board)) {
                            board[row][col] = d + '0';
                            if (solver(board))
                                return true;
                            board[row][col] = '.';
                        }
                    }
                        return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solver(board); }
};

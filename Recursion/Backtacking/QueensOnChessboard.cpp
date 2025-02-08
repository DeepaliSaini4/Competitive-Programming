/*
Description
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and 
you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input Format
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output Format
Print one integer: the number of ways you can place the queens.

Sample Input 1
........
........
..*.....
........
........
.....**.
...*....
........

Sample Output 1
65
*/
#include <bits/stdc++.h>
using namespace std;

const int n = 8;
char queen[n][n]; // Chessboard state

bool check(int row, int col) {
    // Check for column and diagonal threats
    for (int pr = 0; pr < row; pr++) {
        for (int pc = 0; pc < n; pc++) {
            if (queen[pr][pc] == 'Q') {
                if (pc == col || abs(row - pr) == abs(col - pc)) {
                    return false;
                }
            }
        }
    }
    return queen[row][col] != '*'; // Cell should not be blocked
}

int rec(int level) {
    if (level == n) return 1;
    int ans = 0;
    for (int ch = 0; ch < n; ch++) {
        if (check(level, ch)) {
            // Place queen
            queen[level][ch] = 'Q';
            ans += rec(level + 1);
            // Remove queen (backtrack)
            queen[level][ch] = '.';
        }
    }
    return ans;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> queen[i][j];
        }
    }
    cout << rec(0) << '\n';
}

int main() {
    solve();
    return 0;
}

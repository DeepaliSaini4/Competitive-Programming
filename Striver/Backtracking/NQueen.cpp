// funfact - On an N×N board, the maximum number of queens that can be placed
// without attacking each other is N.
//**There must be exactly one queen per row and one queen per column.
class Solution {
public:
    bool issafe(int r,int c,int n,vector<int>&placed){
        for(int i=0;i<r;i++){
            if(placed[i]==c || abs(r-i)==abs(placed[i]-c)) return false;
        }
        return true;
    }

    void placequeens(vector<vector<string>>& config, vector<string> r, int n,
                     vector<int> placed, int row) {
        // base case
        if (row == n) {
            config.push_back(r);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (issafe(row,i,n,placed)) {
                placed[row] = i;
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (j == i)
                        s += "Q";
                    else
                        s += ".";
                }
                r.push_back(s);
                placequeens(config, r, n, placed, row + 1);
                r.pop_back();
                placed[row] = -1;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> config;
        vector<string> r;
        vector<int> placed(n, -1);
        placequeens(config, r, n, placed, 0);
        return config;
    }
};
//tc = n!

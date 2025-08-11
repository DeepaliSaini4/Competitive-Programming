/*
A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j]
is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.
Note that M[i][i] is always 0.
Examples:
Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]
Output: 1
Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.*/

class Solution {
public:
    int celebrity(vector<vector<int>> &M) {
        int n = (int)M.size();
        if (n == 0) return -1;

        int a = 0, b = n - 1;
        while (a < b) {
            if (M[a][b] == 1) ++a;   // a knows b -> a not celeb
            else --b;                // a doesn't know b -> b not celeb
        }
        int c = a;

        for (int i = 0; i < n; ++i) {
            if (i == c) continue;
            if (M[c][i] == 1) return -1; // celeb knows no one
            if (M[i][c] == 0) return -1; // everyone knows celeb
        }
        return c;
    }
};

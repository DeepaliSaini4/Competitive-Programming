class Solution {
public:
    const int VAL = 1e6;
    const int MAX_VISITS = 20000;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool solver(int row, int col, int tarow, int tarcol, set<pair<int, int>>& b,
                set<pair<int, int>>& visited) {
        if (row == tarow && col == tarcol)
            return true;
        if (visited.size() >= MAX_VISITS)//“I've wandered too far for this to be a trap.”
            return true;
        visited.insert({row, col});
        // choice
        for (int i = 0; i < 4; i++) {
            int x = row + dr[i];
            int y = col + dc[i];
            if (x >= 0 && y >= 0 && x < VAL && y < VAL &&
                b.find({x, y}) == b.end() &&
                visited.find({x, y}) == visited.end()) {
                if (solver(x, y, tarow, tarcol, b, visited))
                    return true;
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                          vector<int>& target) {
        set<pair<int, int>> blockedSet;
        for (auto& b : blocked)
            blockedSet.insert({b[0], b[1]});

        set<pair<int, int>> visited1, visited2;
        bool fromSource = solver(source[0], source[1], target[0], target[1],
                                 blockedSet, visited1);
        bool fromTarget = solver(target[0], target[1], source[0], source[1],
                                 blockedSet, visited2);
        return fromSource && fromTarget;
    }//Because one might be trapped, even if the other is not. You need both ends to be reachable to guarantee the path.
};

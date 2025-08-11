using state = pair<int, int>;
class Solution {
public:
    bool isvalid(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    // directions
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        int days = 0;
        int tot = 0;
        int cnt = 0;
        queue<state> qu;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0)
                    tot++;
                if (grid[i][j] == 2)
                    qu.push({i, j});
            }
        }
        while (!qu.empty()) {
            int k = qu.size();
            cnt += k;
            while (k--) {
                auto now = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++) {
                    int x = now.first + dx[i];
                    int y = now.second + dy[i];
                    if (!isvalid(x, y, n, m) || grid[x][y] != 1)
                        continue;

                    grid[x][y] = 2;
                    qu.push({x, y});
                }
            }
            if (!qu.empty())
                days++;
        }
        return (cnt == tot) ? days : -1;
    }
};

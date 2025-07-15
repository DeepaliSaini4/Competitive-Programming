#include <bits/stdc++.h>
using namespace std;

vector<int> distinctNumbers(vector<int>& nums, int k) {
    int size = nums.size() - k + 1;
    int head = -1;
    int tail = 0;
    unordered_map<int, int> g;
    vector<int> ans;

    while (head + 1 < nums.size()) {
        head++;
        g[nums[head]]++;

        if (head - tail + 1 == k) {
            ans.push_back(g.size());
            // Now, slide the window
            g[nums[tail]]--;
            if (g[nums[tail]] == 0)
                g.erase(nums[tail]);
            tail++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> nums = {1, 2, 3, 2, 2, 1, 3}; // fixed: use { }
    int k = 3; // fixed: missing semicolon
    vector<int> ans = distinctNumbers(nums, k);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}

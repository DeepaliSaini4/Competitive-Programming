/* You are given k sorted arrays, each of size k. Merge all the arrays into one sorted array and return it.
You should use an efficient algorithm with O(k² log k) time complexity. */
class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        vector<int> ans;

        // Min-heap storing: (value, array index, element index)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // Step 1: Push the first element of each array into heap
        for (int i = 0; i < k; ++i) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], i, 0});
            }
        }

        // Step 2: Keep popping the smallest and pushing next from that array
        while (!pq.empty()) {
            auto [val, row, col] = pq.top(); pq.pop();
            ans.push_back(val);

            // If there's a next element in the same array, push it
            if (col + 1 < arr[row].size()) {
                pq.push({arr[row][col + 1], row, col + 1});
            }
        }

        return ans;
    }
};

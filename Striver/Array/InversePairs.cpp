class Solution {
public:
    void merge(int high, int low, int mid, vector<int>& nums) {
        vector<int> temp; // to store the sorted stuff
        int left = low;
        int right = mid + 1; // starting index of the right part that is smaller than the left
        // sorting and building on the sorted array in the temp
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        // excesss elements left on the left half just tranfer to temp
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        // excess elements are left on the right half
        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // transerfering all the elements to the original
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    int countpairs(int l, int h, int m, vector<int>& nums) {
        int right = m + 1; // starting index for the right half to be merged
        int cnt = 0;
        for (int i = l; i <= m; i++) {
            while (right <= h && nums[i] > 2LL * nums[right]) {
                right++;
            }
                cnt += (right - (m + 1));
        }
        return cnt;
    }
    int mergesort(int high, int low, vector<int>& nums) {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergesort(mid, low, nums);
        cnt += mergesort(high, mid + 1, nums);
        cnt += countpairs(low, high, mid, nums);
        merge(high, low, mid, nums);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size() - 1;
        return mergesort(n, 0, nums);
    }
};

/*
Given an array of N integers and an integer D. Consider all subarrays with length D, the penalty of the subarray is the number of distinct elements present in the subarray.
Find a subarray of length D with minimum penalty. Print the minimum penalty.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

int freq[1000001] = {0};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = k;
        int current = 0;
        int currSum = 0;
        while (current < n)
        {
            if (freq[arr[current]] == 0)
                currSum++;
            freq[arr[current]]++;
            if (current >= k)
            {
                freq[arr[current - k]]--;
                if (freq[arr[current - k]] == 0)
                    currSum--;
            }
            if (current >= k - 1)
                ans = min(ans, currSum);
            current++;
        }
        for (int i = n - k; i < n; i++) freq[arr[i]]--;
        cout << ans << "\n";
    }
}

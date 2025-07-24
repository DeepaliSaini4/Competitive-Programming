/*
Q-an array of N integers and an integer D. consider all subarray with length D, the penality of the subarray is the number of distinct elements present in subarray.
find a subaaray of length D with minimum penalty
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int freq[10000];
void solver()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int tail = 0;
    int head = -1;
    int ans = 0;
    int dis_cnt = 0;
    int min_dis = 1e9;
    while (tail < n)
    {
        while (head + 1 < n && (head - tail + 1) < d)
        {
            head++;
            if (freq[a[head]] == 0)
            {
                dis_cnt++;
            }
            freq[a[head]]++;
        }
        ans = head - tail + 1;
        if (ans==d)
        {   
            min_dis = min(min_dis, dis_cnt);
        }
        if (tail > head)
        {
            tail++;
            head = tail - 1;
        }
        else
        {
            freq[a[tail]]--;
            if (freq[a[tail]] == 0)
            {
                dis_cnt--;
            }
            tail++;
        }
    }
    cout << min_dis;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solver();
    }
    return 0;
}
/*
test case
1
6 3
0 1 1 2 2 2
ans:
1
*/

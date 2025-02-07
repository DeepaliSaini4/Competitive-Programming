/*
Description
You are given N blocks. You have to build towers by placing blocks on top of each other with the condition that the upper block must be smaller than the lower block. You have to process the blocks in the given order. Find the minimum possible number of towers you can create.

Input Format
The first line of the input contains one integer 
T - the number of test cases. Then T test cases follow.


The first line of each test case contains one integer 
N - the length of the array.


The second line of each test case contains 
N space-separated integers.

Output Format
For each test case, print the minimum possible number of towers you can create.
t is guaranteed that the sum of N over all test cases does not exceed 10^6.
 

Sample Input 1
3
5
3 2 5 1 4
4
1 1 1 1
5
5 4 5 3 2 

Sample Output 1
2
4
2
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
void solver()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
       cin>> arr[i];
    multiset<int> ms;
    ms.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int block = arr[i];
        auto ub_ind = ms.upper_bound(block);// this upper bound has the complexity logn for set
        if (ub_ind != ms.end())
        {
            ms.erase(ub_ind);
            ms.insert(block);
        }
        else
            ms.insert(block);
    }
    cout << ms.size()<<'\n';
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

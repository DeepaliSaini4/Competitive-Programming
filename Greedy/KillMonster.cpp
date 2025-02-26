/*
Problem Statement
There are N monsters in front of you. To defeat the i-th monster, you need an army of A[i] soldiers, out of which B[i] will be killed during the battle.

You want to determine the minimum number of soldiers you need to recruit in order to defeat all the monsters.
The order of battles does not matter—only the total number of recruits required is important.

Input Format
The first line contains an integer T (1 ≤ T ≤ 10^5), the number of test cases.
Each test case consists of:
A single integer N (1 ≤ N ≤ 10^5), the number of monsters.
The next N lines each contain two space-separated integers:
A[i] (1 ≤ B[i] ≤ A[i] ≤ 10^9): The number of soldiers required to defeat the i-th monster.
B[i]: The number of soldiers lost after the battle.
It is guaranteed that the sum of N over all test cases does not exceed 5 × 10^5.

Output Format
For each test case, print a single integer—the minimum number of soldiers required to defeat all the monsters.

Constraints
1≤T≤10^5
1≤N≤10^5
1≤B[i]≤A[i]≤10^9

Sum of N over all test cases ≤ 5 × 10^5
Sample Input 1
2
2
7 4
5 1
3
4 1
6 4
5 3
Sample Output 1
6
5
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
         vector<pair<int,int>> mons(n);
        
        for (int i = 0; i < n; i++) {
            cin >> mons[i].first >> mons[i].second;
        }
        //sorting using a. custom comparator
        sort(mons.begin(),mons.end(),[] (const pair<int,int> &a, const pair<int,int> &b){
            return a.first - a.second > b.first - b.second;
        });

        int max_sold = 0, left_sold = 0;

        for (int i = 0; i < n; i++) {
            max_sold +=max(0LL, mons[i].first - left_sold);
            left_sold = max(1LL*mons[i].first,left_sold);//multiplying with 1LL as both quantites should be of same nature
            left_sold-=mons[i].second;

        }
        cout << max_sold << '\n';
    }
    return 0;
}

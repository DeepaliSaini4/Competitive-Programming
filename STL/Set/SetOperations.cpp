/*
Description
You are given two sets, A and B of N and M integers respectively. There are no duplicate integers in each respective array. Find the set union, set intersection and set 
difference (A-B) of the two sets in sorted order.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, M - the length of the sets.

The second line of each test case contains N space-separated integers.

The third line of each test case contains M space-separated integers.

Output Format
For each test case, print the set union, set intersection and set difference (A-B) of the two sets  in sorted order, each on a separate line.
onstraints
1≤ T ≤ 105
1≤ N, M ≤ 104
1≤ Ai, Bi ≤ 109

It is guaranteed that the sum of N and the sum of M over all test cases does not exceed 2*10^5.

Sample Input 1
3
4 5
2 4 1 5
4 5 6 9 3
2 3
4 5
6 7 1
3 3
1 2 3
1 2 3

Sample Output 1
1 2 3 4 5 6 9 
4 5 
1 2 
1 4 5 6 7 

4 5 
1 2 3 
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;

#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

int main() {
  IOS int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    set<int> uni, inter, diff;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      uni.insert(x);
      inter.insert(x);
      diff.insert(x);
    }
    set<int> inters;
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      uni.insert(x);
      if (inter.find(x) != inter.end()) {
        inters.insert(x);
      }
      if (diff.find(x) != diff.end()) {
        diff.erase(x);
      }
    }
    for (int i : uni) {
      cout << i << " ";
    }
    cout << "\n";
    for (int i : inters) {
      cout << i << " ";
    }
    cout << "\n";
    for (int i : diff) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}


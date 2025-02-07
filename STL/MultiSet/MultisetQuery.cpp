/*
Description
You are given Q queries and have to perform the following operations:

add x - add element x in the set
erase x - delete one element with value x, if it exists
eraseall x - delete all elements with value x, if it exists
find x - if x is present print “YES”, else print “NO”
count x - print the number of times x occurs in the set
print - print the values in set
empty - empty the set
Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


The first line of each test case contains one integer Q - the number of queries.


Each of the next Q lines contains queries.


The combination of print and n does not exceed 10^8.

Output Format
For each test case, print the required queries.

Constraints
1≤ T ≤ 105
1≤ Q ≤ 105
1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1
1
13
add 3
add 1
add 5
add 3
add 3
count 3
erase 3
print
eraseall 3
print
find 5
empty
find 5

Sample Output 1
3
1 3 3 5 
1 5 
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solver()
{
    int q;
    cin >> q;
    multiset<int> st;
    while (q--) {
      string s;
      cin >> s;
      if (s == "add") {
        int x;
        cin >> x;
        st.insert(x);
      } else if (s == "erase") {
        int x;
        cin >> x;
        if (st.find(x) != st.end()) {
          st.erase(st.find(x));
        }
      } else if (s == "eraseall") {
        int x;
        cin >> x;
        if (st.find(x) != st.end()) {
          st.erase(x);
        }
      } else if (s == "find") {
        int x;
        cin >> x;
        if (st.find(x) != st.end()) {
          cout << "YES\n";
        } else {
          cout << "NO\n";
        }
      } else if (s == "count") {
        int x;
        cin >> x;
        cout << st.count(x) << "\n";
      } else if (s == "print") {
        for (int i : st) {
          cout << i << " ";
        }
        cout << "\n";
      } else {  // empty
        st.clear();
      }
    }
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

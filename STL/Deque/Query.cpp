/*
Description
You are given Q queries and have to perform the following operations:insertback x - Add element x at the end of the deque.
eraseback - Delete the end element of the deque, if the deque is not empty.
insertfront x - Add element x at the front of the deque.
erasefront - Delete the front element of the deque, if the deque is not empty.
printfront - Print the element at the front of the deque, if the deque is not empty; otherwise, print 0.
printback - Print the element at the back of the deque, if the deque is not empty; otherwise, print 0.
print x - Print the x-th element of the deque (0-indexed), if it exists; otherwise, print 0.
Input Format
The first line of the input contains one integer 
T - the number of test cases. Then 
T test cases follow.

The first line of each test case contains one integer Q - the number of queries.
Each of the next Q lines contains a query.
Output Format
For each test case, print the required queries.

Constraints
1≤T≤10^5
1≤Q≤10^5
1≤X≤10 ^6
 
It is guaranteed that the sum of Q over all test cases does not exceed 10^5.

Sample Input 1
1
8
insertback 3
insertback 5
insertfront 2
printback
print 1
eraseback
insertfront 1
printfront

Sample Output 1
5
3
1  
  */
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solver() {
    int q;
    cin >> q;
    deque<int> dq;

    while (q--) {
        string s;
        cin >> s;

        if (s == "insertback") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (s == "eraseback") {
            if (!dq.empty()) dq.pop_back();
        } else if (s == "insertfront") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (s == "erasefront") {
            if (!dq.empty()) dq.pop_front();
        } else if (s == "printfront") {
            cout << (dq.empty() ? 0 : dq.front()) << '\n';
        } else if (s == "printback") {
            cout << (dq.empty() ? 0 : dq.back()) << '\n';
        } else if (s == "print") {
            int x;
            cin >> x;
            cout << (x >= 0 && x < dq.size() ? dq[x] : 0) << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solver();
    }
    
    return 0;
}
//>>operations for deque are similar to that of a vector with an additional _back and _+front to specify in which direction you are performing the operation
//The deque (double-ended queue) in C++ uses a dynamic array of fixed-size arrays as its underlying container.

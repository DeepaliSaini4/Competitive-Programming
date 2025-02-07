/*
Description
You are given Q queries and have to perform the following operations:

add x - Add element 
x to the set.
erase x - Delete the element with value 
x, if it exists.
find x - If 
x is present, print “YES”; otherwise, print “NO”.
print - Print the values in the set.
empty - Empty the set.
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
1≤X≤10^6
 
It is guaranteed that the sum of Q over all test cases does not exceed 10^ 5.

Sample Input 1
1
7
add 3
add 2
add 7
print
find 2
erase 2
find 2

Sample Output 1
2 3 7 
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;
void solver()
{
    int q;
    cin >> q;
    set<int> st;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            st.insert(x);
        }
        else if (s == "erase")
        {
            int x;
            cin >> x;
            auto it = st.find(x);
            if (it != st.end())
            {
                st.erase(it);
            }
        }
        else if (s == "find")
        {
            int x;
            cin >> x;
            auto it = st.find(x);
            if (it != st.end())
            {
                int index = 0;
                for (auto i = st.begin(); i != it; i++)
                {
                    index++;
                }
                cout << "YES"<<'\n';
            }
            else
                cout << "NO" << '\n';
        }
        else if (s == "print")
        {
            // print the entire set using iterators from the begin to the end  of the set
            for (auto i = st.begin(); i != st.end(); i++)
            {
                cout << *i << " ";
            }
            cout<<'\n';
        }
        // empty query
        else
        {
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

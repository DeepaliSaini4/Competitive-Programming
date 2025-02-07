/*
escription
There are N students in section A. The i-th student got Ai marks. The class teacher of section B was absent so sections A and B were merged. The students of section B did not want to humiliate themselves, so they decided to sit with students having the same marks as them. You are given the marks of students of section B in order of their entry in the class. You have to tell whether the i-th student of section B can sit with a student with the same marks as him. If there is at least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. (without the quotes)

See Sample Test Cases.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N and M - the number of students in sections A and B, respectively.
The second line of each test case contains N space-separated integers A1,A2,…,AN- the grades of students in section A.
The third line of each test case contains M space-separated integers B1,B2,…,BM - the grades of students in section B.

Output Format
For each test case, print M strings on a new line. Print ‘YES’ if there is at least 1 person in the room with the same IQ. Otherwise, print ‘NO’. (without the quotes)

Constraints

1≤T≤10

1≤N,M≤10^5

1≤Ai,Bi≤10^12

Sample Input 1
2
3 5
2 5 4
7 4 1 4 5
4 4
1 1 8 2
8 3 3 5

Sample Output 1
NO
YES
NO
YES
YES
YES
NO
YES
NO
*/
#include <bits/stdc++.h>
using namespace std;
void solver()
{
    int n1, n2;
    cin>> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n1; i++)
    {
       mp[arr1[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if (mp.count(arr2[i]))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
            mp[arr2[i]]++;
        }
    }
}
int main()
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

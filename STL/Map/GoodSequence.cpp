/*
Description
You are given an array A of N integers. A sequence is called good if the value x occurs x times in the array. Find the minimum number of integers you need to delete from A 
to make it good.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer N - the length of the array.
The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the minimum number of integers you need to delete from A to make it good.
Constraints

1≤T≤10^5
1≤N≤10^5
1≤Ai≤10^9
It is guaranteed that the sum of N over all test cases does not exceed 10^6.
*/
#include <bits/stdc++.h>
using namespace std;
void solver()
{ // taking input
    int s;
    cin >> s;
    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mymap;
    // put the array enteries to the map to create a value-freuency map
    for (int i = 0; i < s; i++)
    {
        mymap[arr[i]]++;
    }

    // solving
    int count = 0; // denotes the minimum number of deletions to be made in order to make a map a good map
    for (auto it : mymap)//it here is a pair datatype
    {
        // entire entry has to be removed as occurrence is less than the value
        if (it.second < it.first)
        {
            count += it.second;
        }
        // difference has to removed and the entry can be made valid
        else if (it.second > it.first)
        {
            count += (it.second - it.first);
        }
    }
    cout<<count<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solver();
    }
    return 0;
}

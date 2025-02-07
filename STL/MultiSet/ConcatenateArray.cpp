/*
Description
You are given an array A of N integers. Find the length of the largest increasing subsequence if the array A is concatenated to itself N times. A sequence A is a subsequence of an array B if A can be obtained from B by deletion of several (possibly, zero or all) elements. The longest increasing subsequence should be strictly increasing.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


The first line of each test case contains one integer N - the length of the array.


The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the length of the largest increasing subsequence if the array A is concatenated to itself N times.
Constraints

1≤T≤2×10^5
1≤N≤10^6
1≤Ai≤10^9
 


It is guaranteed that the sum of N over all test cases does not exceed 10^6.

Sample Input 1
3
3
2 1 3
5
3 1 1 1 4
4
3 2 1 4

Sample Output 1
3
3
4
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solver(){
int n;
cin>>n;
set<int>s;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    s.insert(x); // inserting all elements in the set so that only distict elements are considered
}
cout<< s.size()<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solver();
    }
    return 0;
}

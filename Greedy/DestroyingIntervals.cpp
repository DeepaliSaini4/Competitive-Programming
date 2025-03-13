/*
Description
There are n intervals. The ith interval covers range [li,ri]  including points l and r.
You can destroy intervals by choosing some points. Suppose a point x is chosen, then any interval that covers x will be destroyed.
Find the minimum number of points to be selected to destroy all intervals.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains n, the number of intervals.
Each of n next lines contain two integers , li and ri .

Output Format
For each testcase print a single integer, minimum points required.

Constraints
T ≤ 20
0 ≤ n ≤ 105
0 ≤ li ≤ ri ≤ 109

Sample Input 1
1
3
1 4
2 6
7 10

Sample Output 1
2
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){

    int n;
    cin>>n;

    vector<pair<int,int>>arr;

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        arr.push_back(make_pair(l,r));
    }

    //sort wrt R value 
    sort(arr.begin(),arr.end(),[](pair<int,int>a,pair<int,int>b){
       return a.second<b.second;
    });

    int points = 0;
    int curr = -1e9;

    for(auto it:arr){
        if(it.first>curr){
            points++;
            curr = it.second;
        }
    }

    cout<<points<<'\n';
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}

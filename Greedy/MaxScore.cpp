/*
Description
You are given an array A of n integers and a value k. You can select zero or more non-empty subarrays A[l..r] such that no two subarrays have any index in common, i.e., no two subarrays should overlap. For each chosen subarray A[l..r] add the value A[r]-A[l]-k to your score which is initially zero. Print the max score possible.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains two integers n and k.
Second line contains n integers, Ai , the array A.

Output Format
For each test case print the max score possible in a new line.

Constraints
T ≤ 100
1 ≤ n ≤ 2*105
0 ≤ Ai , k ≤ 109
Sum of n over all test cases is ≤ 2*105

Sample Input 1
2
6 2
4 2 3 7 5 6
6 0 
4 2 3 7 5 6

Sample Output 1
3
6
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> done(n), in_progress(n);
    done[0] = 0;
    in_progress[0] = -arr[0];


    for(int i =1; i<n; i++){
        // two choices
        // Either carry forward the previous `done` value (not choosing A[i])
        // Or choose a subarray ending at `i` and update `done[i]` accordingly.
            done[i] = max(done[i - 1], arr[i] + in_progress[i - 1] - k);
        // Either continue the previous in-progress subarray
        // Or start a new subarray at index `i`
            in_progress[i] = max(in_progress[i - 1], done[i - 1] - arr[i]);   
    }
    cout<<done[n-1]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}

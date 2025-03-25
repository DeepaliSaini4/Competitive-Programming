/*
you are given an array of N integers. For each position, find the nearest position to its left having a smaller value. (1-based indexing)

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array.

The second line of each test case contains N space-separated integers.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) cout<<"0 ";
            else cout<<st.top()+1<<" ";
            st.push(i);
        }
        cout<<"\n";
    }
    return 0;
}

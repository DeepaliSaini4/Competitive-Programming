/*
You are given an array of N integers. In one operation, remove any two elements in the array and add their sum to the array. The cost of this operation will be the sum of the two elements.
Print the minimum cost till the size of the array does not become 1.
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
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pq.push(x);
        }
        int cost = 0;
        while(pq.size()!=1){
            int ele1= pq.top();
            pq.pop();
            int ele2 = pq.top();
            pq.pop();
            cost += ele1 + ele2;
            pq.push(ele1+ele2);
        }
        cout<<cost<<'\n';
    }
    return 0;
}

//In K sized window get the max element in the subarray when an array of size n is given to you.

#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct monotonic_deque{
    deque<int> dq;
    void insert(int x){
        while(!dq.empty() && dq.back()<x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void erase(int x){
        if(!dq.empty() && dq.front() == x) 
        dq.pop_front();
    }
    int getmax(){
        return dq.front();
    }
};

void solver(){
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    monotonic_deque dq;

    for(int i=0;i<n;i++){
        dq.insert(arr[i]);
        if(i>=k) dq.erase(arr[i-k]);
        if(i>=k-1) cout<<dq.getmax()<<" ";   
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();
    return 0;
}

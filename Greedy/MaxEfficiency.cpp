/*
Q -> given strength and efficiency of each n employee calculate the maximum efficiency of the k employees to be 
be selected out of n.
need to maximize (sum of strength)*min efficiency out of all the 'k' 
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

struct student{
    int s,e;
};

bool cmp(student&p1,student&p2){
    return p1.e < p2.e;
}

struct topk{
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
    int ksum = 0;
    void init(int _k){
        k =_k;
        ksum = 0;
    }
    void insert(int x){
        pq.push(x);
        ksum +=x;
        if(pq.size()>k){
            int sm= pq.top();
            pq.pop();
            ksum-=sm;
        }
    }
    int getsum(){
        return ksum;
    }
};

void solver(){
    int n,k;
    cin>>n>>k;
    student arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].s>>arr[i].e;
    }
    sort(arr,arr+n,cmp);
    
    topk mytopk;
    int ans =0;
    
    mytopk.init(k-1);
    for(int i=n-1;i>=0;i--){
        if(n-i>=k){
            int strength = mytopk.getsum() + arr[i].s;
            int effi = arr[i].e;
            ans = max(ans,strength*effi);
            
        }
         mytopk.insert(arr[i].s);
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}

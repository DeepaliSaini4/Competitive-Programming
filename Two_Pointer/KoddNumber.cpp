/*
Given an array of N integers, find a subarray with at most K odd numbers and the total sum is maximum but not more than D. 
If no such subarray exists print "IMPOSSIBLE" without double-quotes.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    int n, k, d;
    cin >> n >> k >> d;
    
    vector<int> arr(n);
    vector<int> prefix(n, 0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        prefix[i] = arr[i];
        if(i) prefix[i] += prefix[i-1];
    }
    
    multiset<int> mt;
    int head = -1;
    int tail = 0;
    int oddcnt = 0;
    int best = -1e18;
    while(tail<n){
        while(head+1<n && ((oddcnt<k && (arr[head+1]%2))||(oddcnt <=k && arr[head+1]%2==0))){
            head++;
            if(arr[head]%2)oddcnt++;
            mt.insert(prefix[head]);
        }
        int base = (tail==0?0:prefix[tail-1]);
        auto it = mt.upper_bound(base+d); //need to find <=base+d in prefix sum
        if(it!=mt.begin()){
            it--;
            best = max(best, *it - base);
        }
        if(head<tail){
            tail++;
            head = tail -1;
        }else{
            if(arr[tail]%2) oddcnt--;
            mt.erase(mt.find(prefix[tail]));
            tail++;
        }
    }
    if(best==-1e18){
        cout<<"IMPOSSIBLE\n";
    }else{
        cout<<best<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solver();
    return 0;
}

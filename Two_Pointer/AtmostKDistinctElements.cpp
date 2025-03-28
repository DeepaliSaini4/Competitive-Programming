// find the number of subarrays having number of distinct elemnents atmost k that is less than equal to k.
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //head and tail
    int tail = 0, head = -1;
    
    // datastucture for the window
   map<int,int> mp;
   int distinct_cnt = 0;
   int ans = 0;
    while(tail<n){
        while(head + 1 <n && (distinct_cnt<k || mp[arr[head+1]]>=1)){
            head ++;
            //insert ds(head)
            if(mp[arr[head]]==0) distinct_cnt++;
            mp[arr[head]]++;
        }
        ans +=(head - tail +1);
        if(tail>head){
            //when we have zero elements in the window
            tail++;
            head = tail -1;
        }else{
            //erase from data structure
            mp[arr[tail]]--;
            if(mp[arr[tail]]==0)
            distinct_cnt--;
            tail++;
        }
    }
    
   cout<<ans<<'\n';
}

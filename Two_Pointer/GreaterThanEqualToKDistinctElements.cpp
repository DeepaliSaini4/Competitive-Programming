/*
number of subarray for which number of distict elements is greater then equal to k
*/
#include<bits/stdc++.h>
using namespace std;

int freq[1000100];
int distinct_cnt = 0;
int arr[1000100]; 

int main(){
    
    int n,k;
    cin>>n>>k;
    k = k-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //head and tail
    int tail = 0, head = -1;
    
    // datastucture for the window
   int distinct_cnt = 0;
   int ans = 0;
    while(tail<n){
        while(head + 1 <n && (distinct_cnt<k || freq[arr[head+1]]>=1)){
            head ++;
            //insert ds(head)
            if(freq[arr[head]]==0) distinct_cnt++;
            freq[arr[head]]++;
        }
        ans +=(head - tail +1);
        if(tail>head){
            //when we have zero elements in the window
            tail++;
            head = tail -1;
        }else{
            //erase from data structure
            freq[arr[tail]]--;
            if(freq[arr[tail]]==0)
            distinct_cnt--;
            tail++;
        }
    }
    
   cout<<(n*(n-1))/2-ans<<'\n';
}

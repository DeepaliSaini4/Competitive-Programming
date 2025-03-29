/*when arr[i]<=10^6 then we have can take a frequency array instead of map to refuce the time complexity for insertion operations from logn to o(1)*/
#include<bits/stdc++.h>
using namespace std;

int freq[1000100];
int distinct_cnt = 0;
int arr[1000100]; 

int main(){
    
    int n,k;
    cin>>n>>k;
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
    
   cout<<ans<<'\n';
}
//no need to clear the globally declared freq array incase of distinct test cases as this two 
//two pointers code magically resets the entire freq array to original one after finishing execution

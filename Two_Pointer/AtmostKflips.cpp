// flip atmost k positions to find the longest subarray with only 1's possible to be created.
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
    int cntzero = 0;
    int ans = 0;
    while(tail<n){
        while(head + 1 <n && (arr[head+1]==1 || cntzero<k)){
            head ++;
            //include element at head in the ds
            if(arr[head]==0)cntzero++;
        }
        ans = max(ans , head-tail+1);
        
        if(tail>head){
            //when we have zero elements in the window
            tail++;
            head = tail -1;
        }else{
            //change ds because if removing tail element
            if(arr[tail]==0) cntzero--;
            tail++;
        }
    }
    
   cout<<ans<<'\n ';
}

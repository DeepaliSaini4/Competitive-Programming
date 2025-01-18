/*
    input
    10
    1 5 7 10 9 6 7 9 2 3
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n;
    cin>>n;
    int arr[n];
    int insertedat[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> lis;
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            insertedat[i] = lis.size();
        }
        else{
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            insertedat[i] = it-lis.begin()+1;
        }

    }
 
    vector<int> final_lis;
    int curlen = lis.size();
    for(int i=n-1;i>=0;i--){
        if(insertedat[i]==curlen){
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }
    reverse(final_lis.begin(),final_lis.end());
    for(auto v:final_lis){
        cout<<v<<" ";
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
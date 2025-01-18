/*
    input
    10
    1 5 7 10 9 6 7 9 2 3
*/
//------------------> ZENITH APPROACH
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
//-------------------------> KING APPROACH 
#include<bits/stdc++.h>
using namespace std;

void solver(){
    int n;
    cin>>n;
    int arr[n];
    vector<int>par;
    int maxi = -1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
    }
    par.assign(maxi+1, 0);
    
    vector<int>lis;
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            par[arr[i]] = lis.empty() ? -1 : lis.back();
            lis.push_back(arr[i]);
        } else {
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it  =arr[i];
            par[arr[i]] = *(--it);
        }
    }
        
    vector<int> fin_lis;
    fin_lis.push_back(lis.back());
    for(int i=lis.back(); i>=0; ) {
        if(par[i] == -1) break;
        fin_lis.push_back(par[i]);
        i = par[i];
    }
    
    for(int i=fin_lis.size()-1; i>=0; i--) cout << fin_lis[i] << " ";
}
    
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}

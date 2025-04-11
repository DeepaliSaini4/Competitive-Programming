// given a string p find positions where it appears in string s;
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    
    string p,t;
    cin>>p>>t;
    
    string w;
    w = p + '#' + t;
    //now creating the kmp array for this string
    
    int n = p.length() + t.length() + 1;
    
    int kmp[n+1];
    kmp[0] = -1;
    int j = -1;//indexing variable
    int i = 0;//iterating variable
    
    while(i<n){
        while(j!=-1 && w[j]!=w[i])
        j = kmp[j];
        j++;
        i++;
        kmp[i] = j;
    }
    //counting how many times it had occurred
    int cnt = 0;
    for(auto it:kmp){
        if(it==p.length()){
            cnt++;
        }
    }
    cout<<"The Number of times Pattern P has appeared in string T = "<<cnt<<'\n';
    
    int endindex=-1;
    for(int i=p.length()+1;i<=n;i++){
        if(kmp[i]==p.length()){
            endindex = i;
            cout<<(endindex - p.length()) - (p.length() + 1)<<'\n';
        }
    }
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--)
    solver();
    
    return 0;
}

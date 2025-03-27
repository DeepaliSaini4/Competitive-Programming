//You are given an integer N. You have to find all the permutations of N in lexicographic order.
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin>>n;
    
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    do{ for(auto it:v){
        cout<<it<<" ";
    }
    cout<<'\n';
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
int w[3003];
int v[3003];
int W;

// O(n*W)--> cost to build it for the first time as followed by caching in the subsequent functionss
int dp[3003][3003];
int rec(int i,int x){
    //pruning
    //base case
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][x]!=-1){
        return dp[i][x];
    }
    //transition
    int ans= rec(i+1,x);
    if(w[i]<=x){
        ans = max(ans,rec(i+1,x-w[i])+v[i]);
    }
    //save and return
    return dp[i][x] = ans;
}

vector<int> solution;

void generate(int i,int x){
    if(i==n){
        return;
    }
    else{
        int donttake = rec(i+1,x);
        if(w[i]<=x){
            //can possibly take 
            int take = rec(i+1,x-w[i])+v[i];
            if(donttake>take){
                generate(i+1,x);
            }else{
                solution.push_back(i);
                generate(i+1,x-w[i]);
            }
        }else{
            //cant't take
            generate(i+1,x);
        }
    }
}

void solver(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,W)<<"\n";
    generate(0,W);
    cout<<solution.size()<<endl;
    for(auto v:solution){
        cout<<v<<" ";
    }
    cout<<'\n';
}

int main()
{ solver();
    return 0;
}

//TC = O(N*W^2)
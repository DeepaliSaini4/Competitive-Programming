#include<bits/stdc++.h>
using namespace std;

//assigning globals as passing in functions has a small overhead
 int n;
 int queen[10];//state storing data structure

bool check(int row, int col){
    //check if we can place the queen without getting attacked
    for(int pr=0;pr<row;pr++){
        int pc= queen[pr];
        // (pr,pc) has a queen. Check if it attacks (row,col)
        if(pc==col || abs(row-pr) == abs(col-pc))
        return 0;
    }
    return 1;
}

int rec(int level){//level == row number
    //Recursion meaning...
    //given that you have decided [0...level-1] in queens
    //explores all possible solutions by deciding [level....n-1]
    //and count them.
    
    //base case
    if(level == n){
        return 1;
    }
    //recursive case
    int ans = 0;
    for(int ch=0;ch<n;ch++){
        //go through all the choices
        if(check(level,ch)){
            //move
            //place
            queen[level] = ch;
            //go into recursion to next level
            ans += rec(level+1);
            //unplace
            queen[level] = -1;
        }
    }
    return ans;
}

void solve(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
    
    cout<<rec(0)<<'\n';
}

signed main(){
    solve();
    return 0;
}

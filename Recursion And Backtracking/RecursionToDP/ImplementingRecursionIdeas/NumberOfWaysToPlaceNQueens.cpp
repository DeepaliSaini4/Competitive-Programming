#include<bits/stdc++.h>
using namespace std;

int n;
int queen[20]; //queen[i]-->where is my queen in the row i.
bool check(int row,int col){
    for(int i=0;i<row;i++){
        int prow = i;
        int pcol = queen[i];
        
        if(pcol==col || abs(col-pcol)==abs(row-prow))//checking the digonal condition as for diagonal they are at 45degree facing each  other
        return 0;
    }
    return 1;
}
int rec(int level){//rec-->number of ways to populate [level..n-1] rows for a valid configuration
    //level -> row in which we are placing the queen
    
    //pruning
    
    //base case
    if(level==n){
        return 1;
    }
    //compute
    int ans=0;
    //love over all choices
    for(int col=0;col<n;col++){
        //check if the choice is valid
        if(check(level,col)){
            //place the queen
            queen[level] = col;
            //explore the option
            ans +=rec(level +1);
            //revert placing the queen
            queen[level] = -1;
            
        }
    }
    //return
    return ans;
}

void solver(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
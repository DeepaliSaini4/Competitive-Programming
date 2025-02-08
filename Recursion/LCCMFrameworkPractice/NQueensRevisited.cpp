/*
Description
An S-Queen is a chess piece that combines the power of a knight and a queen.
Find the number of ways to place N S-Queens on an N x N chessboard.

Input Format
The input contains only single integer N denoting the side of the chessboard. 

Output Format
Print the number of ways to place N S-Queens on the N x N chessboard.

Constraints
2 ≤ N ≤ 14

Sample Input 1
3
Sample Output 1
0
Sample Input 2
10
Sample Output 2
4
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
int queen[15];//stores the state 

bool check(int row,int col){
    for(int pr=0;pr<row;pr++){
        if(col==queen[pr] || abs(row-pr)==abs(col-queen[pr])) return 0;
        if((abs(pr-row) == 2 && abs(queen[pr]-col) == 1) || (abs(queen[pr]-col) == 2 && abs(pr-row) == 1)) {   
            return 0;
        }

    }
    return 1;
}

int rec(int level){//returns the number of queens that can be placed from[level.....n-1] provided that intital state array for the previous placements of thew queens
    //base case
    if(level == n){
        // valid arrangements of all queens made
        return 1;
    }
    int ans = 0;
    //choice -> chose col in a given row that is in a given row
    for(int col=0;col<n;col++){
        //check -> valid place?
        if(check(level,col)){
            //move -> place the queen
            queen[level]=col;

            ans+=rec(level+1);
            //backtrack -> unplace the queen
            queen[level] =-1;
        } 
    }
    return ans;
}

void solver(){
    cin>>n;
    memset(queen,-1,sizeof(queen));
    cout<<rec(0)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}

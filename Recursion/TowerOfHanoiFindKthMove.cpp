#include<bits/stdc++.h>
using namespace std;

#define int long long 

void kthmove(int disc, int source, int target, int aux, int k){
    //we have three types of moves
    //move disc-1 from source to aux  --> 2^(n-1) - 1 moves
    if(k<=((1<<(disc-1))-1)){
        kthmove(disc-1,source,aux,target,k);
    }
    //move 1 disc from source to target --> 1 move
    else if(k==(1<<(disc-1))){
        cout<<"Moving disc "<<disc<<" from "<<source<<" to "<<target<<"\n";
        return;
    }
    //move disc-1 from aux to source --> 2^(n-1) - 1 moves
    else{
        kthmove(disc-1,aux,target,source,k-(1<<(disc-1)));
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        for(int i=1;i<=7;i++){
            kthmove(3,1,3,2,i);
        }
}

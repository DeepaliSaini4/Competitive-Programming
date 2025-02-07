/*
Q - Move the tower of prgs from A to C.
*/
#include<bits/stdc++.h>
using namespace std;

void tower_hanoi(int x,char source,char target,char aux){
    //base case
    if(x==0){
        return;
    }
    //recursive case
    tower_hanoi(x-1,source,aux,target);
    cout<<"move peg "<<x<<" from "<<source<<" to "<<target<<"\n";
    tower_hanoi(x-1,aux,target,source);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    tower_hanoi(4,'A','B','C');
    return 0;
}

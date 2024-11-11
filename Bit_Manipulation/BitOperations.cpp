/*
A state with n flags of ON or OFF can be represented by a sequence of bits where 0,1,...,n−1 -th flag corresponds to 1 (ON) or 0 (OFF). The state can be managed by the corresponding decimal integer because the sequence of bits is a binary representation where each bit is 0 or 1.

Given a sequence of bits with 60 flags that represent a state, perform the following operations. Note that each flag of the bits is initialized by OFF.

test(i): Print 1 if ith flag is ON, otherwise 0.
set(i): Set ith flag to ON
clear(i): Set ith flag to OFF
flip(i): Inverse ith flag
all: Print 1 if all flags are ON, otherwise 0
any: Print 1 if at least one flag is ON, otherwise 0
none: Print 1 if all flags are OFF, otherwise 0
count: Print the number of ON flags
val: Print the decimal value of the state

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solver(){
    int nq;
    cin >> nq;

    int num=0;

    while(nq--) {
        int q;
        cin>>q;

        if(q==1){
            int i;
            cin>>i;
            cout<<((num & (1LL<<i))>0)<<'\n';
        }
        else if(q==2){
            int i;
            cin>>i;
            num |= (1LL<<i);
        }
        else if(q==3){
            int i;
            cin>>i;
            num &= (~(1LL<<i));
        }
        else if(q==4){
            int i;
            cin>>i;
            num ^= (1LL<<i);
        }
        else if(q==5){
            cout<<(__builtin_popcountll(num)==60)<<'\n';
        }
        else if(q==6){
            cout<<(num>0)<<'\n';
        }
        else if(q==7){
            cout<<(num==0)<<'\n';
        }
        else if(q==8){
            cout<<__builtin_popcountll(num)<<'\n';
        }
        else{
            cout<<num<<'\n';
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
/*
input
14
2 0
2 1
2 2
3 1
1 0
1 1
1 2
1 3
4 3
5
6
7
8
9
ouput:
1
0
1
0
0
1
0
3
13
notes--->

C ( Concept/topic used in the problem) -> Bit manipulation

D (Debug issues faced, what to keep in mind next time) ->

__builtin_popcount() works for 32 bits.﻿

__builtin_popcountll() works specifically for 64 bits designed for long long type
*/
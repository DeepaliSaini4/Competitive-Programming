/*
Question 6 Given a positive integer n, find the count of positive integers i such that 0 <= i <= n and n+i=n^i.

Example:

10 => 4
18 => 8
*/
// xor is adddition without carrying and number with carry is addition without carry
// here addition with carry is equal to addition without carry means that there is no carry in addition on both the sides
// Question becomes find how many numbers are there when added to n doesnot generate any carry 
//forming such a number in bits for positions having bit 1 in n we can only have 0 in the required number so that no carry forms and for positions having 0 we can have either of 0 and 1.
// ans = 2^(number of zeros).

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt_unset = 0;
    while(n>0){
        if((n&1)==0)
            cnt_unset++;
         n>>=1;
        
    }
     cout<< (1<<cnt_unset)<<'\n';
    return 0;
}

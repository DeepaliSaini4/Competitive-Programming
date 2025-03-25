/*
You are given a string S. Find the minimum number of parentheses you should add to make the parentheses valid.

A parentheses is valid if:

It is an empty string
It can be written as AB where A and B are valid parentheses
It can be written as (A) where is a valid parentheses
Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one string S.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    string s;
    cin >> s;

    int depth = 0;
    int unbalanced = 0;

    for(auto it : s){
        if(it == '(') 
            depth++;
        else{
            if(depth>0)
            depth--;
            else{
                unbalanced++;
                }
           }
        }
        cout << depth + unbalanced << '\n'; 
    }


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while(t--) solver();
    return 0;
}

/*
Description
Using characters: . (dot) and * (asterisk) print a grid-like pattern as shown in the sample test case.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.The first line of each test case contains two space-separated integers 
N, M.

Output Format
For each test case, print the required pattern.

Constraints
1≤T≤10^4
1≤N,M≤1000
It is guaranteed that the sum of N×M
N×M over all test cases does not exceed 10^6.

Sample Input 1
3
3 4
4 2
3 3

*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************
*..*..*..*..*
*..*..*..*..*
*************
*******
*..*..*
*..*..*
*******
*..*..*
*..*..*
*******
*..*..*
*..*..*
*******
*..*..*
*..*..*
*******
**********
*..*..*..*
*..*..*..*
**********
*..*..*..*
*..*..*..*
**********
*..*..*..*
*..*..*..*
**********
*/
#include<iostream>
using namespace std;
 
 
void helper(int i,int j,int r,int c) {
    if(i%3==0 || j%3==0 )
    cout<<"*";
    else
    cout<<".";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        for(int i=0;i<3*r+1;i++) {
            for(int j=0;j<3*c+1;j++) {
                helper(i%3,j,r,c);
            }
            cout << '\n';
        }
    }
    return 0;
}

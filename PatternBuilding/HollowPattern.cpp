/*
Description
Given two integers N and M, print a hollow rectangle pattern of length N and width M using the '*' character.

A hollow rectangle is a rectangle where the borders are filled with '*' and the interior is empty (spaces).

Input Format
The first line contains an integer T denoting the number of test cases.
For each test case, there is a line containing two numbers N and M, the length and width of the rectangle.

Output Format
For each test case, print the pattern.

Sample Input 1
1
2 2

Sample Output 1
**
**

Sample Input 2
2
4 4
4 4

Sample Output 2
****
*  *
*  *
****

****
*  *
*  *
****

Sample Input 3
1
4 5

Sample Output 3
*****
*   *
*   *
*****
*/
#include<iostream>
using namespace std;
 
void helper(int i,int j,int r,int c) {
    if(i==0 || i==r-1||j==0||j==c-1)
    cout<<"*";

     else cout<<" ";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            int r,c;
            cin>>r>>c;
            for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                helper(i,j,r,c);
            }
            cout << '\n';
        }
    }
 
    return 0;
}

/*
Description
Given a number N and an array A of N numbers. Print all array positions that store a number less than or equal to 10 and the number stored in that position.

Input Format
The first line contains T, the number of test cases.
For each test case:
The first line contains a number N, the number of elements.

The second line contains N numbers.
It's guaranteed that there is at least one number in array less than or equal to 10.

Output Format
For each number in the array that is equal to or less than 10 print a single line containing A[i] = X, where i is the position in the array and X is the number stored in the position.

Sample Input 1
1
5
1 2 100 0 30

Sample Output 1
A[0] = 1
A[1] = 2
A[3] = 0
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a<=10){
                cout<<"A["<<i<<"] = "<<a<<"\n";
            }
        }
    }
    return 0;
}

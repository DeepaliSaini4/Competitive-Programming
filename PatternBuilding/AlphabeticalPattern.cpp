/*
Description
Print the first N rows where the ithrow contains the first i capital letters.

Input Format
The first line contains the number T of test cases.
For each test case:
There is only one line containing N, which is the number of rows in the pattern.

Output Format
For each test case, print the pattern.

Constraints
1≤T≤26
1≤N≤26

Sample Input 1
1
1

Sample Output 1
A

Sample Input 2
2
4
7

Sample Output 2
A
AB
ABC
ABCD
A
AB
ABC
ABCD
ABCDE
ABCDEF
ABCDEFG

Sample Input 3
1
5

Sample Output 3
A
AB
ABC
ABCD
*/
#include<iostream>
using namespace std;
 
 
void helper(int j) {
   cout<<char('A'+j);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int t;
    cin>>t;
    while(t--){
            int n;
            cin>>n;
           for(int i=0;i<n;i++) {
               for(int j=0;j<=i;j++) {
                   helper(j);
               }
               cout << '\n';
        }
    }
    return 0;
}

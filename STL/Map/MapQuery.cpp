/*
Description
You are given Q queries and have to perform the following operations:

add x y - add student name X (string in lowercase alphabets) with marks y (integer). If it already exists, update.
erase x - erase marks of student with name x, if the entry exists
print x - print marks of student with name x, if entry is not there for x, print 0.
Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


The first line of each test case contains one integer Q - the number of queries.


Each of the next Q ines contains queries.

Output Format
For each test case, print the required queries.

Constraints
1≤ T ≤ 105
1≤ Q ≤ 105
1≤ |S| ≤ 50
1≤ Y ≤ 106


It is guaranteed that the sum of Q over all test cases does not exceed 105.

Sample Input 1
1
5
add alice 24
add bob 21
print alice
erase alice
print alice

Sample Output 1
24
0
*/
#include<bits/stdc++.h>
using namespace std;
void solver(){
 //q is the number of querries as input
 int q;
 cin>>q;
 map<string,int> record;
 while(q--){
    string s;
    cin>>s;
        if(s=="add"){
            string name;
            cin>>name;
            int marks;
            cin>>marks;
            record[name]=marks;
        }
         if(s=="print"){
            string name;
            cin>>name;
            cout<<record[name]<<'\n';
        }
        if(s=="erase"){
            string name;
            cin>>name;
            record.erase(name);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //t test cases
    int t;
    cin>>t;
    while(t--){
        solver();
    }
    return 0;
}

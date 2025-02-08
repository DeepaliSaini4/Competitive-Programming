/*
Description
You are given Q queries and have to perform the following operations:

add x - add element x at the end of vector
remove - delete last element of the vector, if vector is not empty
print x - print the x-th character of the vector, if it exists, otherwise print 0. (0-indexing)
clear - empty the vector
Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.


The first line of each test case contains one integer Q - the number of queries.


Each of the next Q ines contains queries.

Output Format
For each test case, print the required queries.

Sample Input 1
1
9
add 3
add 4
print 1
remove
add 7
add 2
print 0
clear
print 0

Sample Output 1
4
3
0
*/
#include<bits/stdc++.h>
using namespace std;

void solver(){
    int q;
    cin>>q;
    vector<int>v;
    while(q--){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            v.push_back(x);
        }
        else if(s=="remove"){
            if(!v.empty()){
                v.pop_back();
            }
        }
        else if(s=="print"){
            int x;
            cin>>x;
            if(x<v.size()){
                cout<<v[x]<<'\n';
            }
            else cout<<"0\n";
        }
        else{
            v.clear();
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)
    solver();
    return 0;
}

/*
Description
You are given a string s and two integers x and y. You can perform two types of operations any number of times.
Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

Input Format
The first line contains an integer T (number of test cases), 1 ≤ T ≤ 10^5.
The next T lines contain a string S and 2 space-separated integers S, X, Y where 1 ≤ X,Y ≤ 10^9, 1 ≤ |S| ≤ 10^6.
Sum of |S| across all test cases ≤ 10^7.

Output Format
For each test case print the maximum point possible in a new line.

Constraint:
1 ≤ T ≤ 10^5
1 ≤ X,Y ≤ 10^9
1 ≤ |S| ≤ 10^5.
Sum of |S| across all test cases ≤ 10^6.

Sample Input 1
4
abdsbab 23 50
babababa 45 32
ujaabba 4 5
cxbaeab 17 9

Sample Output 1
73
167
9
26
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    string s;
    cin>>s;
    int p1,p2;
    cin>>p1>>p2;
    string s1 = "ab";
    string s2 = "ba";

    // the bigger value string is s1
    if(p2>p1){
        string temp = s1;
        s1=s2;
        s2=temp;
        int p=p1;
        p1=p2;
        p2=p;
    }
    //removing all instances of s1 from s first
    stack<char>st;
    int cnt1 = 0;
    for(int i=0;i<s.length();i++){
        if(!st.empty() && s[i]==s1[1] && st.top()==s1[0]){
            st.pop();
            cnt1++;
        }
        else {
            st.push(s[i]);
        }
    }
    string m;
    while(!st.empty()){
        m += st.top();
        st.pop();
    }

    reverse(m.begin(),m.end());

    //Now from string m remove all the instances of string s2

    int cnt2 =0;
    for(int i=0;i<m.length();i++){
        if(!st.empty() && m[i]==s2[1] && st.top()==s2[0]){
            st.pop();
            cnt2++;
        }
        else{
            st.push(m[i]);
        }
    }
    cout<<((p1*cnt1)+(p2*cnt2))<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}

/*
Description
You are given a string s containing lower case alphabets. You need to answer q queries of the form (l,r,k):Here 
(l,r) denotes the end points of a substring of s. You are allowed to arrange the characters in this substring in any possible manner. Besides, you can perform atmost 
k number of substitutions . In each substitution, you can replace the letter at any index of the substring with another letter of your choice. You need to check if the 
given substring can be converted into a palindrome using these conditons.After processing all the queries, you need to print a string ans of length 
q which stores the answer to all the queries in the following manner - If the substring in the i th  query can be converted into a palindrome, then 
ans i='1', otherwise 
ans i='0'.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains the string s.

The second line of each test case contains the number of queries q.

The next q lines of each test case contain 3 space-separated integers - l, r and k.

Output Format
For each test case, print the string ans on a new line.

Sample Input 1
1
cdecd
4
1 1 0
1 2 1
1 3 1
1 4 0

Sample Output 1
1110
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    string s;
    cin>>s;

    int n = s.length();

    int q;
    cin>>q;

    vector<vector<int>>freq(n,vector<int>(26,0));
    
    for(int i=0;i<n;i++){
        if(i>0)freq[i] = freq[i-1];
        freq[i][s[i]-'a']++;
    }

    while(q--){
        int oddc = 0;
        int l,r,k;
        cin>>l>>r>>k;
        l--;r--; // zero based indexing
        for(int i=0;i<26;i++){
            int ch = freq[r][i]-(l>0?freq[l-1][i]:0);
            if(ch%2==1)oddc++;
        }
        cout<<(oddc/2<=k?'1':'0');
    }cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}
//Total: O(n + q) per test case 

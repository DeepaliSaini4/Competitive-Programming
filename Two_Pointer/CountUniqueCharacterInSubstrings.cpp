/*
Given a string S consisting of the lowercase character of length N. 
Score of a string is the number of unique characters present in the string( characters which are only present once in the string).
Like score of "character" is 3 {h,t,e}.

Find the sum of the score of all substring of S.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int letter[26]; 

void solver(){
    int n;
    cin>>n;

    string s;
    cin>>s;

   vector<int> occurence[26];
   for(int i=0;i<26;i++)occurence[i].push_back(-1);
   for(int i=0;i<n;i++) occurence[s[i]-'a'].push_back(i);
   for(int i=0;i<26;i++) occurence[i].push_back(n);
   int ans = 0;
   for(int i=0;i<26;i++){
    for(int j=1;j<occurence[i].size()-1;j++){
        ans +=(occurence[i][j]-occurence[i][j-1])*(occurence[i][j+1]-occurence[i][j]);
    }
   }
   cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();
    return 0;
    
}

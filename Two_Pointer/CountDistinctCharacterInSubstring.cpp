/*
Given a string S consisting of lowercase characters of length N.
The score of a string is the number of distinct characters present in the string.
For example, the score of "character" is 6.

Find the sum of the scores of all substrings of S.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){

    int n;
    cin>>n;

    string s;
    cin>>s;

    int prev[26];//stores the last occurrence index of an character mapped at an index 
    for(int i=0;i<26;i++) prev[i] = -1;

    int ans = 26*n*(n + 1)/2;// the contibution of all 26 characters is assumed to be rpesent in all the substrings initially.
    for(int i=0;i<n;i++){
        int gap = i - prev[s[i]-'a'] - 1;
        ans = ans - ((gap*(gap + 1))/2);//subtracting the substrings where the character is missing
        prev[s[i]-'a'] = i;//updating the last occurrence 
    }
    for(int i = 0;i<26;i++){
        int gap = n - prev[i] - 1;
        ans = ans - ((gap*(gap + 1))/2);
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
/*
First for loop: Removes substrings where a given character is missing on the left (before it first appears).
Second for loop: Removes substrings where a given character is missing on the right (after its last appearance).
*/

//given a string find the min number of characters you can append at the back so the string becomes a palindrome.
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    string s;
    cin>>s;
    string r = s;
    reverse(r.begin(),r.end());
    string s_= r + '#' + s;
    int kmp[s_.length()+1];
    int j = -1;
    int i = 0; //iterating index
    kmp[0] = -1;
    
    while(i<s_.length()){
        while(j!=-1 && s_[i]!=s_[j]){
            j = kmp[j];
        }
        i++;
        j++;
        kmp[i] = j;
    }
    
    int ans = s.length()-kmp[s_.length()];
    cout<<"The max number of characters to append at the end of the string s to make it palindronme is: "<<ans<<"\n";
    
    string substr_tobeadded ="";
    for(int i=0;i<ans;i++){
        substr_tobeadded+=s[i];
    }
    cout<<"substr to be added in the end to make string s plaindrome is: ";
    reverse(substr_tobeadded.begin(),substr_tobeadded.end());
    for(auto it:substr_tobeadded){
        cout<<it;
    }
    cout<<"\n";
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    
    while(t--) solver();
    
    return 0;
}

/*Given a string s, determine if it can be made a palindrome by deleting at most one of its characters.
If s[i] is deleted, the resulting string is the concatenation of s[0 : i - 1] and s[i + 1 : n - 1], where n is the size of s.
If yes, print Y, else print N.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        bool decided = false;
        string s;
        cin>>s;
        int i=0;
        int n = s.length();
        int j = n-1;
        while(i<j){
            if(s[i]!=s[j]){
                string r = s;
                r.erase(i, 1); 
                string k = s;
                 k.erase(j, 1); 
                 cout << (isPalindrome(r) || isPalindrome(k) ? "Y\n" : "N\n");
                  decided = true;
                break;
            }else{
                i++;j--;
            }
        }
        if (!decided) cout << "Y\n";                        
    }
}

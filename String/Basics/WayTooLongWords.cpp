/*
Given a string S. Print the original string if it's not too long, otherwise, print the special abbreviation.

Note: The string is called too long if its length is strictly more than 10 characters. If the string is too long, then you have to print the string in the following manner:

Print the first character in the string.
Print the number of characters between the first and the last characters.
Print the last character in the string.
For example: "localization" will be "l10n", and "internationalization" will be "i18n".
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
        string s;
        cin>>s;

        int n = s.length();

        if(n<=10) cout<<s<<'\n';
        else {cout<<s[0]<<n-2<<s[n-1]<<'\n';}
            
    }
    return 0;
}

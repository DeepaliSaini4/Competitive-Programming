/*
Given a string S that represents a URL request. Print five lines contains the following format: "X:Y" where X is the parameter and Y is the parameter's value.
Note: The parameters of the 
URL: username, pwd, profile, role and key.

Input Format
Only one line containing a string S. 
It consists of uppercase and lowercase English letters, digits, and special characters.]
The URL will be in the following format:
http://www.{word}.{word}/{word}/{word}?username={word}&pwd={word}&profile={word}&role={word}&key={word} 
It's guaranteed that all parameters will have a value. The value will always be a string of alphabets and digits.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    getline(cin,s);
    size_t pos = s.find('?');
    if(pos!= string::npos){
        string query = s.substr(pos+1);
        stringstream ss(query);
        string token;
        while(getline(ss,token,'&')){
            size_t eq_pos = token.find('=');
            if(eq_pos!=string::npos){
                string param = token.substr(0, eq_pos);
                string value = token.substr(eq_pos+1);
                cout<<param<<": "<<value<<'\n';
            }
        }
    }
    return 0;
}

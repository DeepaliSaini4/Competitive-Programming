/*
Given two numbers N, Q and a string S of size N, followed by Q lines of the following queries:

pop_back : remove the last character in the string.

front : print the first character in the string.

back : print the last character in the string.

sort l r : where1≤l,r≤∣S∣, sort all characters of S from l to r.

reverse l r : where 1≤l,r≤∣S∣, reverse all characters of S from l to r.

print pos : where 1≤pos≤∣S∣, print the character at index pos.

substr l r : where 1≤l,r≤∣S∣, print substring of S from l to r.

push_back x : add character x to the end of the string.

Note: If l>r, then swap them.

For each query, print the answer associated with it in a single line.

It's guaranteed that in the first 7 types of queries, the string is not empty.

It's recommended to use built-in string functions.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,q;
    cin>>n>>q;

    string s;
    cin>>s;
    
    while(q--){
        string qu;
        cin>>qu;

        if(qu == "pop_back") s.pop_back();
        else if(qu == "front") cout<<s[0]<<'\n';
        else if(qu == "back") cout<<s.back()<<'\n';
        else if(qu == "sort"){
            int l,r;
            cin>>l>>r;
            if(l>r) swap(l,r);
            sort(s.begin()+l-1,s.begin()+r);//it excludes the rth character from sorting 
        }
        else if(qu == "reverse"){
            int l,r;
            cin>>l>>r;
            if(l>r) swap(l,r);
            reverse(s.begin()+l-1,s.begin()+r);
        }
        else if(qu == "print"){
            int pos;
            cin>>pos;
            cout<<s[pos-1]<<'\n';
        }
        else if(qu == "substr"){
            int l,r;
            cin>>l>>r;
            if(l>r) swap(l,r);
           string sub = s.substr(l-1,r-l+1);//(starting index,number of characters)to include)
           cout<<sub<<'\n';
        } 
        else if(qu == "push_back"){
            char c;
            cin>>c;
                s.push_back(c);
        }

    }
    return 0;
}
//string built in analogous to vector

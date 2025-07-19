/*
You are given a particular string S, which contains only lowercase English alphabets. 
Your task is to calculate all the occurence of the character and print the character in the order in which it appears in the string 
S followed by the number of occurences.
Each character should appear only once in the output.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<char>order;
        unordered_map<char,int>mymap;
        for(auto it:s){
            if(mymap.find(it)==mymap.end())
                order.push_back(it);
            mymap[it]++;
        }
        for(auto it:order){
            cout<<it<<mymap[it];
        }
        cout<<"\n";
    }
}

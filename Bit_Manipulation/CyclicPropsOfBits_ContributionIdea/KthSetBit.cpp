/*
Q -> string s = "0 1 10 11 100...." formed by concatenation of binary representation of bits of numbers from 0 find index of the kth occurrence of 1.have q queries.
constraints:
1. q<=10, k<=10^5
2^10 ~ 10^3 --> 2^20 ~ 10^6 --> 2 * 10^6
2. q<=10^5 & k<=10^5

3. q<=10^9 & k<=10^9
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

string getbitstr(int x){
    string curr = "";
    while(x){
        if(x%2)curr+='1';
        else curr +='0';
        x/=2;
    }
    if(curr == "")curr = "0"; 
    reverse(curr.begin(),curr.end());
    return curr;
}

signed main(){
    // Pre - Computation
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s = "";
    int cntone = 0;
    int curr_num = 0;
    while(cntone<=100000){
        string cur_bits =  getbitstr(curr_num);
        int new_one = 0;
        for(auto v:cur_bits){
            if(v=='1'){
                new_one++;
            }
        }
       // cout<<curr_num<<" "<<cur_bits<<" "<<new_one<<endl; 
        s += cur_bits;
        cntone+= new_one;
        curr_num++;
    }
    vector<int> pos1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            pos1.push_back(i);
        }
    }
    //once precomputed every query is solved in order O(1).
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        cout<<pos1[k-1]<<'\n';
    }
    
    return 0;
}
// total complexity of the solution will be O(max(k).log2(k)+Q)

/*
Description
Given an array of numbers, that might contain duplicates, print all possible unique permutations in lexicographically increasing order.

Input Format
The first line of input contains n - the size of the array.
The second line contains n space-separated integers denoting the elements of the array - a1, a2, …, an.

Output Format
Print all permutations in lexicographically increasing order. See the sample output for more clarity.

Constraints
1 ≤ n ≤ 8
0 ≤ ai ≤ 10^9

Sample Input 1
3
1 1 1

Sample Output 1
1 1 1

Sample Input 2
3
1 2 1

Sample Output 2
1 1 2 
1 2 1 
2 1 1 
*/
#include<bits/stdc++.h>
using namespace std;

int n;
map<int,int> mp;
vector<int> cur_perm;
vector<vector<int>>all_sol;

void rec(int level){
    if(level==n){
        all_sol.push_back(cur_perm);
        return;
    }
    for(auto v:mp){
        if(v.second!=0){
            mp[v.first]--;
            cur_perm.push_back(v.first);
            rec(level+1);
            cur_perm.pop_back();
            mp[v.first]++;
        }
    }
}

void solver(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    rec(0);
    for(auto v:all_sol){
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}

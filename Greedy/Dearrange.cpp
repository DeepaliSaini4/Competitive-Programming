/*
Description
You are given an array A of n integers. You can perform as many swap operations as you want. In a swap operation you can swap the elements at any two positions. 
Define score as number of indices i such that after all the operations, Ai is different from the original value of Ai. Print the maximum score possible.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains n.
Second line contains n integers, ith integer is Ai .

Output Format
For each testcase print the maximum score possible in a new line.

Constraints
T ≤ 10
1 ≤ n ≤ 105
1 ≤ Ai ≤ 106

Sample Input 1
1
3
1 2 3

Sample Output 1
3
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n;
    cin>>n;

    map<int,int>mp; //maintaining a frequency map to track the elemnet with largest occurence

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        mp[num]++;
    }

    int max_occurrence = 0;
    
    for(auto it:mp) max_occurrence = max(max_occurrence,it.second);

    if(max_occurrence>n/2){
        cout<< 2*(n-max_occurrence)<<'\n';
    }else{
        cout<<n<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}

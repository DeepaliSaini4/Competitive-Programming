/*
You are given a list of 
N students with their names and roll numbers. Sort the list according to their roll numbers.

Input Format
The first line of the input contains one integer 
T - the number of test cases. Then T test cases follow. For each test case:

The first line contains an integer N - the number of students.
Each of the next N lines contains a string S and an integer R - the name and roll number of a student
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

bool comp(pair<string,int>&a,pair<string,int>&b){
    return a.second<b.second;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

       vector<pair<string,int>> student(n);

        for(int i=0;i<n;i++) cin>>student[i].first>>student[i].second;
        sort(student.begin(),student.end(),comp);

        for(auto it:student){
            cout<<it.first<<" "<<it.second<<'\n';
        }

    }

}

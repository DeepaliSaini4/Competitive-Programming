/*Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.*/
#include<bits/stdc++.h>
using namespace std;

void subsetsum(vector<int>&arr,int i,int sum,set<vector<int>>&ans,vector<int>level){
    //base case ->return case
    if(i == arr.size()){
        sort(level.begin(),level.end());
        ans.insert(level);
        return;
    }
     //take call
    level.push_back(arr[i]);
    subsetsum(arr,i+1,sum+arr[i],ans,level);
    //not take call
    level.pop_back();
    subsetsum(arr,i+1,sum,ans,level);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int>arr = {5,2,1};
    set<vector<int>>ans;
    vector<int>level;
    subsetsum(arr,0,0,ans,level);
    for(auto it:ans){
        for(auto it2:it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//tc = O(2^n * n²)

#include<bits/stdc++.h>
using namespace std;

void subsetsum(vector<int>&arr,int i,int sum,vector<int>&ans){
    //base case ->return case
    if(i == arr.size()){
        ans.push_back(sum);
        return;
    }
    //take call
    subsetsum(arr,i+1,sum+arr[i],ans);
    //not take call
    subsetsum(arr,i+1,sum,ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int>arr = {5,2,1};
    vector<int>ans;
    subsetsum(arr,0,0,ans);
    sort(ans.begin(),ans.end()); ->nlogn
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}
//tc = (2^n log(2^n)).

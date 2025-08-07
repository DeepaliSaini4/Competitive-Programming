/*
You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.
*/
#include <bits/stdc++.h>
using namespace std;

bool placement(vector<int>&stalls,int k,int dist){
    int cows = 1;
    int last_pos = stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i] - last_pos>=dist){
            last_pos = stalls[i];
            cows++;
        }
    }
    return cows>=k;
}

int aggressiveCows(vector<int>&stalls,int k){
    sort(stalls.begin(),stalls.end());
    int lo = 0;
    for(int i=1;i<stalls.size();i++){
        int diff = stalls[i] - stalls[i-1];
        lo = max(diff,lo);
    }
    int hi = (stalls[stalls.size()-1]-stalls[0]);
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(!placement(stalls,k,mid)){
            hi = mid -1;
        }else{
            lo = mid + 1;
        }
    }
    return hi;
}

int main()
{
    vector<int> stalls = {4,2,1,3,6};
    int k = 2;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

/*
roblem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. 
We need to find the minimum number of platforms needed at the railway station so that no train has to wait.
Input: N=6, 
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00} 
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}


*/

#include<bits/stdc++.h>
 using namespace std;
 
 int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }

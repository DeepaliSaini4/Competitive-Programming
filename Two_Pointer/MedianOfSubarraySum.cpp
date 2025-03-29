/*Given an array of N integers A. 
The score of a subarray is the sum of all integers in the subarray. 
Mr.X calculated the score of all N*(N+1))/2 subarray.
Mr.X wants you to find the median of the array containing the score of all the subarray.*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
int arr[100001];


//function to count the number of subarrays with sum<=x
int func(int x){
    int cnt = 0;
    int currSum = 0;
    int left = 0;
    int right = 0;
    while(right < n ){
        currSum+=arr[right];
        while(left<=right and currSum>x){
            currSum-=arr[left];
            left++;
        }
        cnt+=(right-left+1);
        right++;
    }
    return cnt;
}

void solver(){
    cin>>n;

    int low = 0;
    int high = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        high+=arr[i];//sum of all the elements
    }
    int ans = -1;
    int total = (n*(n + 1))/2;//total number of subarrays hence the total number of sums that will be formed or the total umber of score array elements.
    int median = (total + 1)/2; //position of median element
    while(low<=high){
        int mid = (low+high)/2;
        int cntsub = func(mid);
        if(cntsub>=median) 
        high = mid-1,ans = mid;
        else low = mid + 1;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}

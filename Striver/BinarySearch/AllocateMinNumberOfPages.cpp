/*
Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students,
allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.
Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.
*/
#include <bits/stdc++.h>
using namespace std;

bool distributed(int pages,vector<int>&arr,int n,int students){
    int allocated = 1;
    int pageval = 0;
    for(int i=0;i<n;i++){
        if(pageval + arr[i]>pages){
            allocated++;
            pageval = arr[i];
        }
        else pageval+=arr[i];
    }
    return (allocated<=students);
}

int findPages(vector<int>&arr,int n,int m){
  int hi = arr[0];
  int lo = arr[0];
  for(int i=1;i<arr.size();i++){
      hi+=arr[i];
      lo = max(lo,arr[i]);
  }
  while(lo<=hi){
      int mid = (hi+lo)/2;
      if(distributed(mid,arr,n,m)){
          hi = mid - 1;
      }else{
          lo = mid + 1;
      }
  }
  return lo;
  
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

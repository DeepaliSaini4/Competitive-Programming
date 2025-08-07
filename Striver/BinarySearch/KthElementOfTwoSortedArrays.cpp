#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>&a,vector<int>&b,int n,int m,int k){
    if(n>m) return kthElement(b,a,m,n,k);
     int lo = max(0, k - n), hi= min(k, m);//derived condition from mid1+mid2=k
    while(lo<=hi){
        int mid1= (hi + lo)/2;
        int mid2 = k - mid1;
        int l1 =INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1<n) r1 = a[mid1];
        if(mid2<m) r2 = b[mid2];
        if(mid1-1>=0) l1 = a[mid1-1];
        if(mid2-1>=0) l2 = b[mid2-1];
        if(l1<=r2 && l2<=r1) return max(l1,l2);
        else if(l1>r2){
            hi = mid1 - 1;
        }else lo = mid1 + 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-th element of two sorted array is: " <<
            kthElement(a, b, a.size(), b.size(), 5) << '\n';
}

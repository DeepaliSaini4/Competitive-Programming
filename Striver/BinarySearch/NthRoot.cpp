#include <bits/stdc++.h>
using namespace std;

long long binaryexpo(long long  a,long long b){
    if(b==0) return 1;
    else if (b%2!=0) return a*binaryexpo(a,b-1);
    else{
        long long c = binaryexpo(a,b/2);
        return c*c;
    }
}
int nthRoot(int n,int m){
    if(m==1) return 1;
    int low = 2;
    int high = m;
    while(low<=high){
        int mid = low + ((high-low)/2);
        long long midpower = binaryexpo(mid,n);
        if(m == midpower) return mid;
        else if(m > midpower){
            low = mid + 1;
        }else high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = nthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
//logm

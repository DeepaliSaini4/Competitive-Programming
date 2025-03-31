/*
Find the number of unordered pairs of intersecting diagonals in the Convex N-gon. The intersecting point should be inside the polygon.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long  // Redefine int as long long

const int mod = 1e9 + 7;


int bin_pow(int a,int b){
    if(!b) return 1;
    if(b%2) return (a*bin_pow(a,b-1))%mod;
    else{
        int x = bin_pow(a,b/2);
        return (x*x) % mod;
    }
}

int inverse(int x) {
    return bin_pow(x, mod-2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
    
        // Calculate C(n,4) = n! / (4! * (n-4)!)
        int numerator = (((((n*(n-1))%mod)*(n-2))%mod)*(n-3))%mod;
        int denominator = 24;
        int inv_denominator = inverse(denominator);
        int ans = (numerator * inv_denominator);
        
        cout << (((ans % mod) + mod) % mod) << '\n';
    }
    return 0;
}

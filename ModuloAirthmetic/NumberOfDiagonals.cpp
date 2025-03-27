/*
Find the number of diagonals in the Convex N-gon.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int calculator(int n)
{
    int num = (n * (n - 1)) ;
    return ((num / 2) - n) % mod;
}
void solver()
{
    int n;
    cin >> n;
    cout  << calculator(n)%mod<<'\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solver();
    }
    return 0;
}

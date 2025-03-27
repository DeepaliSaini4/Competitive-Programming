/*
There are N piles of stones in front of you. ith pile contains Ai number of stones.
You want to find whether it is possible to split each pile into 1 or more piles of X (≥ 2) stones such that each splitted-pile has exactly X stones.
Note that X should be the same for each pile.

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void helper()
{   int n;
    cin>>n;
    int piles[n];
    for(int i=0;i<n;i++){
        cin>>piles[i];
    }
    int gcd_ = __gcd(piles[0], piles[1]);
    for (int i = 2; i < n; i++)
    {
        gcd_ = __gcd(piles[i], gcd_);
    }
    if (gcd_ > 1)
    {
        cout << "Yes"<<'\n';
        return;
    }
    cout << "No"<<'\n';
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    helper();

    return 0;
}

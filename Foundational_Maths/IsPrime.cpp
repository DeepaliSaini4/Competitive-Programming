//You are given an integer N. You have to tell whether the number is prime or not.

#include <bits/stdc++.h>
using namespace std;

#define int long long

void helper()
{   int n;
    cin>>n;
    bool is_prime = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            is_prime = 1;
            break;
        }
    }
    if(n == 1 || is_prime)
    cout << "NO" << '\n';
    else cout<<"YES\n";
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

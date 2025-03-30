#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
// binpow function uses the concept of binary exponentiation to find a number to the power of given number
/*binary exponentitation:
-->breaks down exponent into tis binary representatiion and uses that to perform further fewer multiplications
-->faster logn method
-->if exponent is odd break it into the 2.2^n-1 then n-1 is even...
-->if exponent is even break it to 2^((n/2)*2) ...
-->whats going on???
simple darling break the number to be calculated into powers of 2(binary form)
//now if power to be calculated is odd break it to one 2 and even 2 power
//calculate even 2 power by halfing it! ;->.
*/
// a is the base and b is the power to be raised
int factorial(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * i) % mod;
    }
    return ans;
}
int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    // power to be calculated is odd
    if (b % 2 == 1)
    {
        return (a * binpow(a, b - 1)) % mod;
    }
    else
    {
        int x = binpow(a, b / 2);
        return (x * x) % mod;
    }
}
int inverse(int b, int p) // O(log(mod))
{
    return (binpow(b, p - 2)) % p;
}
int nCr(int n, int r)
{ // O(n+r)
    int num = factorial(n);
    int deno = (factorial(n - r) * factorial(r)) % mod;
    return ((num * inverse(deno, mod)) % mod);
}
// better one
// n<=10^9, r<=20...n is very large
int nCr2(int n, int r)
{ // O(r)
    int num = 1;
    int den = 1;
    for (int i = 1; i <= r; i++)
    {
        num = num * (n - i + 1) % mod; // cannot directly compute the factorial of n as very arge value of n present
        den = den * (i) % mod;
    }
    return (num * inverse(den, mod)) % mod;
}
// v<=40 and r<=n calculate this **without modulo
int nCr3(int n, int r)
{ // works only for n<=40
    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (n - i + 1);
        ans = ans / i; // in the same iteration compute the fraction of the ans instead of calculating it separately
        /*in the above division by the theorem that "r factorial divides the product of any r consecutive numbers"
        the ans obtained is always an integer so no worries about getting a floor value of a floating point.
        */
    }
    return ans;
}
// n<=1000,r<=n,using modulo that is not prime necessarliy so inverse mnay not exist
int ncr[1001][1001];
int nCr_random_modulo(int n, int r)
{
    ncr[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                ncr[i][j] = (ncr[i - 1][j]) % mod;
            else
                ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
        }
    }
    return ncr[n][r];
}
// q queries n,q,r<=10^6 with %mod
// calculating the factorial using dp
// Most Common Method
int fact[1000100];
void precompute()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
}
int nCr5(int n, int r)
{ // O(n+r)
    int num = fact[n];
    int deno = (fact[n - r] * fact[r]) % mod;
    return ((num * inverse(deno, mod)) % mod);
}
// EVEN FASTER
int incfactorial[1000100];
void precompute_faster()
{
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    incfactorial[1000000] = inverse(fact[1000000], mod);
    for (int i = 1000000; i >= 1; i--)
    {
        incfactorial[i - 1] = incfactorial[i] * i % mod;
    }
}
int nCr6_faster(int n, int r) 
{ //   O(1)
    int num = fact[n];
    int deno = (incfactorial[n - r] * incfactorial[r]) % mod;
    return ((num * deno) % mod);
}
signed main()
{
    cout << binpow(2, 5) << endl;
    // finding inverse
    /*
    b=3;p=7;find b inverse
    by fermats little theroem binverse=b^(p-2)(modp);
    */
    cout << inverse(3, 7) << "\n";
    cout << nCr(7, 1) << "\n";

    // last case of q queries
    int q;
    cin >> q;
    while (q--)
    {
        int n, r;
        cin >> n >> r;
        cout << nCr5(n, r) << "\n";
    }
    return 0;
}
//extreme problem challenger-->sabdwich on codchef

#include<bits/stdc++.h>
using namespace std;
# define int long long
int mod=1e9+7;
int binpow(int a,int b){
    if(b==0)return 1;
    else if(b%2!=0) return (a*binpow(a,b-1))%mod;
    else{
        int x=binpow(a,b/2);
        return (x*x)%mod;
    }
}
void solver(){
//(a)^b^c%p
int a,b,c,p;
cin>>a>>b>>c>>p;
int d=binpow(b,c);
cout <<binpow(a,d)%p; //a^b %p = ((a%p)^b)%p
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solver();
    }
    return 0;
}
/*
Q- find a^b^c%p
//edge case 0^0=1
1
3 1 200 3
ans
0
1
2 4 2 7
ans 2
1
1 6 20 5
ans 1
*/

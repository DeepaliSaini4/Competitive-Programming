#include<bits/stdc++.h>
using namespace std;

using lli = long long;

lli sum_of_bits(lli x){
    lli ans =0;
    lli tot = x+1;
    for(int i=0;i<60;i++){
        lli full = (tot/(1LL<<(i+1)));
        lli left = tot % (1LL<<(i+1));
        lli extra = max(left-(1LL<<i),0LL);
        ans += full *(1LL<<i) + extra;
    }
    return ans;
}

int main(){
    cout<<sum_of_bits(7)<<endl;
}

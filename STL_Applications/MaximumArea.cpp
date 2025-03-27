/*
You have a rectangular sheet of paper with dimensions H×W You make N horizontal and vertical cuts in the sheet. Find the area of the maximum fragment after each cut.

It is guaranteed that there won't be any two identical cuts. Also, the cuts that you make in the previous queries persist on the paper for the next queries.


*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        int h,w,n;
        cin>>h>>w>>n;
        
        set<int> hori, verti;

        hori.insert(0);
        hori.insert(h);
        verti.insert(0);
        verti.insert(w);

        multiset<int> w1,h1;
        w1.insert(w);
        h1.insert(h);
        while(n--){
            int x;
            char c;
            cin>>c>>x;
            if(c == 'H'){
                hori.insert(x);
                auto it = hori.lower_bound(x);
                auto it1 = it, it2=it;
                it1--;
                it2++;
                h1.erase(h1.find(*it2-*it1));
                h1.insert(*it2-*it);
                h1.insert(*it-*it1);
            }else{
                verti.insert(x);
                auto it = verti.lower_bound(x);
                auto it1 = it, it2 = it;
                 it1--;
                 it2++;
                w1.erase(w1.find(*it2-*it1));
                w1.insert(*it2 - *it);
                w1.insert(*it- *it1);
            }
            int ans = (*prev(w1.end()))*(*prev(h1.end()));
            cout<<ans<<"\n";
        }
    }
    return 0;
}

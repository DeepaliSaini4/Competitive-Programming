#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct manacher{
    vector<int>p;
   
    void run_manacher(string s){
        int n = s.length();
        cout<<s<<'\n';
        p.assign(n,1);
        int l = 1;
        int r = 1;
        for(int i=1;i<n;i++){
            p[i] = max(0LL,min(r-i,p[l+r-i]));
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }
            if(i+p[i]>r){
                l = i-p[i];
                r = i + p[i];
            }
        }
        for(auto v:p){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    
    void build(string s){
        string t;
        for(auto v:s){
            t+= string("#")+v;
        }
        run_manacher(t+"#");
    }
    //abbabba
    int getlongest(int cen,bool odd){
        int pos = 2*cen+1+(!odd);
        return p[pos]-1;
    }
    bool checkpalin(int l,int r){
        if((r-l+1)<=getlongest(l+r/2,l%2==r%2)){ return 1;
        }else{
             return 0;
            }
         }
    }m;

void solver(){
    string s = "babbabbabc";
    m.build(s);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--){
        solver();
    }
}

#include<bits/stdc++.h>
using namespace std;

#define int long long 

struct manacher{
    vector<int>p;// Stores the radius of the longest palindrome centered at each position.
   
    void run_manacher(string s){
        int n = s.length();
        cout<<s<<'\n';
        p.assign(n,1);// Start with radius 1 for all positions (each character is its own palindrome).
        int l = 1;// Tracks the farthest-reaching palindrome [l, r].
        int r = 1;
        for(int i=1;i<n;i++){
            // Use mirror symmetry to avoid redundant checks.
            p[i] = max(0LL,min(r-i,p[l+r-i]));
             // Expand the palindrome centered at 'i'.
            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }
             // Update the farthest-reaching palindrome
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
    // Preprocessing the String
    void build(string s){
        string t;
        for(auto v:s){
            t+= string("#")+v;// Insert '#' between characters. Example: "abc" → "#a#b#c"
        }
        run_manacher(t+"#");// Add a final '#'
    }
    //abbabba
    int getlongest(int cen,bool odd){
        int pos = 2*cen+1+(!odd);// Convert original string's center to preprocessed position.
        return p[pos]-1;// Adjust for the '#' characters.
}
    }

//Check If Substring is a Palindrome
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

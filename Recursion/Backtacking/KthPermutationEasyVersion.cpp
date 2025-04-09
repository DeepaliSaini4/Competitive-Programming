#include<bits/stdc++.h>
using namespace std;

#define int long long 

vector<int>s;//stores the unused elements 
vector<int>v;//stores the current permutation
int n,k;
int pcount;//stores the lexicographical count of the current premutation that had formed

void findkthpermutation(int level){
   if(level==n){
    pcount++;
    if(pcount==k){
        for(auto it:v){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    return;
   }
   for(int i=0;i<n;i++){
    if(s[i]!=-1){//if the element is not used yet
        v[level] = s[i];//put the element in the current level
        s[i] = -1;//amrk the leemnt as used
        findkthpermutation(level+1);//go to the next level
        s[i] = v[level]; //backtrack unmark and restore
    }

   }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    v.assign(n,0);
    for(int i=1;i<=n;i++)s.push_back(i);
    findkthpermutation(0);
   return 0;
}

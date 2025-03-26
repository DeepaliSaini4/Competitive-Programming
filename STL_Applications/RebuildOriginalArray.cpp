/*
Your class teacher wrote ( N ) integers on the board. One of your classmates was being mischievous;
he replaced the ( N ) integers with all possible subset sums of the array when the teacher was not in the class.

Suppose that the integers on the board were ([2,1]), then the subsets will be: ({}, {2}, {1}, {2,1}) and the subset sums will be: ({0,2,1,3}).

Your task is to rebuild the original array given by your teacher.
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
        int n;
        cin>>n;

        multiset<int>mt;
        for(int i=0;i<(1<<n);i++){
            int x;
            cin>>x;
            mt.insert(x);
        }

        vector<int> ans;
        multiset<int> curr,generated;

        curr.insert(0);
        mt.erase(mt.find(0));

        while(!mt.empty()){
            int x = *(mt.begin());
            ans.push_back(x);
            generated.clear();
            for(auto v:curr){
                generated.insert(v+x);
            }
            for(auto v:generated){
                mt.erase(mt.find(v));
                curr.insert(v);
            }
        }
        for(auto v:ans){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int mincount(int amount,vector<int>&change){
    int ans = 0;
    int i = change.size()-1;
    while(i>=0){
        if(change[i]<=amount){
            ans ++;
           amount -=change[i];
        }else{
            i--;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int> change = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int amount = 70;
    cout<<mincount(amount,change)<<'\n';
    return 0;
}

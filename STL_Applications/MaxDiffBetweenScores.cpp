/*
There are N cards with scores Ai and Bi written on them, representing scores for players PA and PB, respectively.
Two players, PA and PB, take turns picking cards, adding the value on the card to their total score.
The goal is to maximize the difference between the total scores of the two players (SA - SB), where SA and SB represent the total scores of players PA and PB, respectively.
*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>cards(n);
    for(int i=0;i<n;i++)cin>>cards[i].first>>cards[i].second;
    sort(cards.begin(),cards.end(),[&](pair<int,int>&a,pair<int,int>&b){
        return a.first + a.second > b.first + b.second;
    });
    for(auto v:cards){
        cout<<v.first<<" "<<v.second<<'\n';
    }
    
}

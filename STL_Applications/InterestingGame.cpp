/*
Alice and Bob are playing a new game, which is very interesting and fun. The game is as follows:

The game starts with two n-sized integer arrays, A and B, and is played by two players, P1 and P2 .
The players move in alternating turns, with P1  always moving first. During each move, the current player must choose an integer, i, such that0≤i≤n−1.
If the current player is P1, then P1 receives Ai points.
If the current player is P2, then P2 receives Bipoints.
Each value of i can be chosen only once. That is, if a value of i is already chosen by some player, none of the players can re-use it. So, the game always ends after n moves.
The player with the maximum number of points wins.
The arrays A and B are accessible to both the players P1 and P2. So the players make an optimal move at every turn.
Given the values of n, A, and B, can you determine the outcome of the game? P1is Alice, and P2is Bob.
Print ‘Alice’ if Alice will win, 'Bob' if Bob will win, or 'Tie' if they will tie. Assume both players always move optimally.

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    int n;
    cin>>n;

    int a[n];
    int b[n];

    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=0;i<n;i++) cin>>b[i];
     
    //optimal choice is not just picking the max element but also blocking the maximum element for the other player

    vector<pair<int,pair<int,int>>>sum_ab;
    for(int i=0;i<n;i++){
        int sum = a[i] + b[i];
        sum_ab.push_back(make_pair(sum,make_pair(a[i],b[i])));
    }

    //sorting in the descending order
    sort(sum_ab.begin(),sum_ab.end(),[](pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
        return a.first > b.first;
    });

    int score_a = 0;
    int score_b = 0;

    for(int i=0;i<n;i++){
        if(i%2==0) score_a += sum_ab[i].second.first;
        else score_b += sum_ab[i].second.second;
    }

    //result printing
    if(score_a>score_b)cout<<"Alice"<<'\n';
    else if(score_a<score_b)cout<<"Bob"<<'\n';
    else cout<<"Tie"<<'\n';

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--)solver();

    return 0;
}

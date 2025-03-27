/*
Bob is standing in a park at (0,0) facing north. He is given a series of instructions to move around the park. The instructions can be:

‘W’: go straight 1 unit
‘L’: turn 90 degrees left
‘R’: turn 90 degrees right
Bob has to perform the given instructions forever. If he is going in a circle forever, print ‘YES’. Otherwise, print ‘NO’ (without the quotes).

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow. The first line of each test case contains N - the length of the input string of instructions. The second line of each test case contains one string S - the series of instructions to move around the park.


*/

#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    /*
    if the position coordinates become (0,0) that is equivalent to the staring coordinates then the motion is circular -> basic idea
    // mapping directions
    0 -> north
    1 -> west
    2 - > south
    3 -> east
    */
    while(t--){
        int n;
        cin>>n;

        string s;
        cin>>s;

        int x = 0;
        int y = 0;
        int direction = 0;//north direction
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(s[i] == 'L')//making a counterclockwise move
            direction = (direction + 3) % 4;
            else if (s[i] == 'R')
            direction = (direction + 1) % 4;
            else{
                if(direction == 0) y++;
                else if ( direction ==1) x--;
                else if ( direction ==2) y--;
                else  x++;

            }
        }
        if((x == 0 && y ==0)|| direction!=0) cout<<"YES"<<'\n';
        else cout<<"NO"<<"\n";

    }
    return 0;
}

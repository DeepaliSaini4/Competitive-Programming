/*
Given a number N and a string S of size N consisting of 5 different uppercase characters only 
(V, W, X, Y, Z).
V: Adds to the score 5 points.
W: Adds to the score 2 points.
X: Removes the next consecutive character from the string.
Y: Moves the next consecutive character to the end of the string.
Z: If the next consecutive character is 
V it divides the total score by 5, but if it is W it divides the total score by 2. 
Then it removes the next consecutive character from the string if and only if the next character is V or W.
Note: In case the string ends with X, Y, or Z, ignore their operations. The score is calculated from left to right and starts with 0.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

    string s;
    cin>>s;

    int score = 0;
    for(int i=0;i<n;i++){
        auto it = s[i];
        if(it == 'V'){
            score += 5;
        }else if(it == 'W'){
            score += 2;
        }else if(it == 'X' && i!= n-1){
            s[i + 1] = '0';
        }else if(it == 'Y' && i!= n-1){
            s.push_back(s[i + 1]);
                n++;
                s[i + 1] = '0';

        }else if(it == 'Z' && i!= n-1){
            if (i != n - 1) {
                if (s[i + 1] == 'W') {
                    score /= 2;
                    s[i + 1] = '0';
                } else if (s[i + 1] == 'V') {
                    score /= 5;
                    s[i + 1] = '0';
                }
            }

        }
    }
    cout << score;
    
}

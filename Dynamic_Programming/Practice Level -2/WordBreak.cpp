/*
Q -> Description
Given a string 
s
s and a dictionary of strings 
w
o
r
d
s
words, output "Yes" if 
s
s can be segmented into a space-separated sequence of one or more dictionary 
w
o
r
d
s
words, else output "No".

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input Format
First-line contains 
T
T - the number of test cases.
The first line of each test case contains 
n
n - the size of the dictionary 
w
o
r
d
s
words.
The second line of each test case contains string s.
The next n lines of each test case contain n words of the dictionary words.

Output Format
For each test case, output "Yes" if 
s can be segmented into a space-separated sequence of one or more dictionary 
words, else output "No".

Constraints

1≤T≤1000
1≤n≤1000
1≤∣s∣≤300

1≤words[i].length()≤20
Sum of ∣s∣ over all test cases is <= 3 X 10^4

Sample Input 1
3
6
ilikealgozenith
algozenith
love
like
i
you
algo
2
applepenapple
apple
pen
3
mississippi
miss
ippi
sis

Sample Output 1
Yes
Yes
No
Note
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n;
string s;
set<string>words;

int dp[301];
bool rec(int level){//can a substring ending at level-1 be segmented into one ore more words form the dictionary
    //pruning
    //base case
    if(words.find(s.substr(0,level+1))!=words.end())//found a word of the dictionary
    return true;
    //cache check
    if(dp[level]!=-1)
    return dp[level];
    //compute
    bool ans = false;
    for(int prev=0;prev<=level;prev++){
        if(words.find(s.substr(prev,level-prev+1))!=words.end()){
            if(prev==0 || (prev && rec(prev-1))){
                ans = true;
                break;
            }
        }  
    }
    //save and return
    return (dp[level] = ans);
}

void solver(){
    cin>>n;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        words.insert(s);
    }
    //Recurrence meaning (form -2)
    // can the given string ending at (level) besegmented into a space separarted sequence of one or more words of the dictionary 
    if(rec(s.size()-1)) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
    words.clear();

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}

/*
Description
You are standing on the lowest row of a chessboard and can only move, upwards and leftwards or upwards and rightwards. There is a predefined score on each cell of the chessboard. You can start from any cell in the lowest row and you have to reach the uppermost row such that your score is the maximum possible and it is divisible by K. You have to find the maximal score you can achieve.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains three space-separated integers N, M, and K - the length of the array.

Each of the next N lines contains M digits from 0-9 indicating the score at that cell.

Output Format
For each test case, if it is possible, you have to find the maximal score you can achieve. If it is impossible print -1.

Constraints
1≤ T ≤ 100

1 ≤ N, M ≤ 100

1≤ K ≤ 11

Sample Input 1
3
4 3 11
194
707
733
633
2 4 2
3916
9593
2 2 4
15
52

Sample Output 1
22
18
-1
 */
 #include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,m,k;
vector<vector<int>>grid;

int dp[105][105][12];
int rec(int i,int j,int rem){
    //pruning
    if(i<0 || j<0 || i>=n || j>=m) return -1e9;
    //base case
    if(i==0){
        if((rem+(grid[0][j])%k)%k==0) return grid[0][j];
         return -1e9;
    }
    //cache check
    if(dp[i][j][rem]!=-1) return dp[i][j][rem];
    //compute
    int score = -1e9;
    score = rec(i-1,j-1,((rem+(grid[i][j])%k))%k)+ grid[i][j];
    score = max(score,rec(i-1,j+1,((rem+(grid[i][j])%k)%k))+ grid[i][j]);
    //save and return
    return dp[i][j][rem] = score;

}

void solver(){
    cin>>n>>m>>k;
    grid.resize(n+1,vector<int>(m+1));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            grid[i][j] = s[j]-'0';
        }
    }
   int max_score = -1;
   for(int i=0;i<m;i++){
    max_score= max(max_score,rec(n-1,i,0));
   }

   cout<<max_score<<'\n';
   grid.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
/*
when using vector globally clear it after each test case.

for globally declared array no need to clear.

Take care with handling the input. (given as string of digits instead of number).

Instead of storing the entire sum uptil a certain level instead store the remainder.(optimal)

*/
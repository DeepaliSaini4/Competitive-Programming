/*
Description
You are given n jobs. The ith job has a duration Li and a deadline Di. Duration is the amount of time it takes to complete the job. Jobs must be completed on or before their
deadline. You can start completing jobs at time 0. Only one job can be taken up at a time. Any job when taken up must be completed fully without switching to any other job.  
If you finish a job at time t then you may start another job at t.Find maximum number of jobs that can be completed from the n given jobs.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains n, the number of jobs.
Second line contains n integers, Di , deadline of the ith job.
Third line contains n integers, Li , duration of the ith job.

Output Format
For each test case print a single integer in a new line: Maximum number of jobs that you can complete.

Constraints
T ≤ 100
n ≤ 20,000
1 ≤ Di, Li ≤ 10^9
Sum of n over all test cases is ≤ 10^5

Sample Input 1
2
2
2 4
2 2
2
3 4
3 3

Sample Output 1
2
1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){

    int n;
    cin>>n;

    vector<pair<int,int>>jobs(n);
    for(int i=0;i<n;i++) cin>>jobs[i].first;
    for(int i=0;i<n;i++) cin>>jobs[i].second;

    jobs.push_back({0,0});

    sort(jobs.rbegin(),jobs.rend());//sort in decreasing order of deadlines

    int ans = 0;
    priority_queue<int>min_heap;//push negatives of durations

    min_heap.push(-jobs[0].second);
    for(int i=1;i<jobs.size();i++)
    {
        int interval = jobs[i-1].first - jobs[i].first;
        while(interval>0 && !min_heap.empty()){
            int duration = -min_heap.top();
            min_heap.pop();
            int spent_time = min(interval,duration);
            interval-=spent_time;
            duration -= spent_time;
            if(duration>0) min_heap.push(-duration);//push remaining job time back
            else ans ++; //job can be completed 
            }
             //push this new job into heap
            min_heap.push(-jobs[i].second);
        }
            cout<<ans<<'\n'; 
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();
    return 0;
}
//O(nlogn)

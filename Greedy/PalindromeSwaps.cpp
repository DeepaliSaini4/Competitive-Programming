/*
Description
X wants to transform a given string s into a palindrome. 
X can interchange the position of any two adjacent characters of the string. X can do this as many time as it wants. What is the minimum number of times it must do this 
to get a palindrome. In case it's impossible, output -1.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains n, size of string .
Second line contains the string s.

Output Format
For each test case if it's possible to trasnform s to a palindrome print the minimum number of swaps, else print -1.

Constraints
T ≤ 20
n ≤ 100
s consists of lowercase alphabets.

Sample Input 1
2
4
aabb
3
abc

Sample Output 1
2
-1
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solver(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    map<char,int>freq;//keep track of frequency of each word

    for(auto it:s){
        freq[it]++;
    }

    int seen_odd = 0;
    for(auto it:freq){
        if(seen_odd == 1 && it.second%2==1){
            cout<<"-1"<<'\n';
            return;
        }
        else if(it.second%2 == 1){
            seen_odd = 1;
        }
    }
    //possible to create palindrome --> need to find the number of swaps
    //L and R pointers starting at each end and check if same, if not search between L and R for element to swap with.
    int L = 0;
    int R = n-1;
    int cnt = 0;
    while(L<=R){
        if(s[L] == s[R]){
            L++;
            R--;
        }else{
            int f = L;
            int b = R;

            while(s[f]!=s[R])f++;//closest to the left pointer where s[R] is occurring
            while(s[b]!=s[L])b--;//closest to the right pointer where s[L] is occurring

            //Swapping from new index to the old index ensures that no extra swaps counted when we have multiple identical items such as in aab where  the L index is a and front is B
            if(f-L<R-b){
                while(f!=L){
                    swap(s[f],s[f-1]);
                    f--;
                    cnt++;
                }
            }
            else{
                while(b!=R){
                    swap(s[b],s[b+1]);
                    b++;
                    cnt++;
                }
            }
            L++;
            R--;
        }
    }
    cout<<cnt<<'\n';  
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();
    return 0;
}
//tc = O (n^2)

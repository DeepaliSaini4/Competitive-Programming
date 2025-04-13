/*
Description
Given a string of length n, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in "algoazzaa" is "azza".
If there are multiple longest palindromic substrings, Output the one which comes first in the string.

Input Format
The first line contains T - the number of test cases.
The first line of each test case contains a string of length n. Each character is one of a–z.

Output Format
For each test case, Output the Longest Palindromic Substring.
If there are multiple longest palindromic substrings, Output the one which comes first in the string.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    string s;
    cin >> s;

    // Preprocess the string with separators
    string t = "#";
    for (char ch : s) {
        t += ch;
        t += "#";
    }

    int n = t.size();
    vector<int> p(n, 1);

    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
            //mirroring logic
            p[i] = min(r - i, p[l + r - i]);
            //expanding the box size
        while (i - p[i] >= 0 && i + p[i] < n && t[i - p[i]] == t[i + p[i]]) {
            p[i]++;
        }
        //updating the box size based on expansion
        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    // finding the max length plaindrome centre and length
    int max_len = 0, center = 0;
    for (int i = 1; i < n; i++) {
        if (p[i] > max_len) {
            max_len = p[i];
            center = i;
        }
    }

    // Extract longest palindromic substring from original string
    int start = (((center - (max_len-1)) )/2);
    cout << s.substr(start, max_len-1) << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) solver();
    return 0;
}

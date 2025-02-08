/*
Description
Write a program to print a pyramid pattern of height N. See the sample examples.

Input Format
The first line contains the number of test cases, T.
For each test case:
A line containing an integer N, denoting the pyramid's height.

Output Format
For each test case, print the pyramid pattern of height N using '*' symbols. Print the outputs for different test cases consecutively without any separator.

Constraints
1≤T≤100
1≤N≤100
*/
#include<iostream>
using namespace std;

void printPyramid(int n) {
    for(int i = 1; i <= n; i++) {
        // Print spaces (each actual space corresponds to two spaces for alignment)
        for(int j = 1; j <= (n - i); j++) {
            cout << "  ";
        }
        // Print '*' symbols with a space in between
        for(int k = 1; k <= (2 * i - 1); k++) {
            cout << "* ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        printPyramid(n);
    }
    return 0;
}

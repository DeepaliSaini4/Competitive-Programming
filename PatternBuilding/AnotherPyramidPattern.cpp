/*
Description
For a given integer N, print the pattern as shown in the examples below.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.The first line of each test case contains the integer N.

Output Format
For each test case, print the desired pattern. Add an empty line after each test case.

Constraints
1≤T≤10
1≤N≤10^2

Sample Input 1
2
3
4

Sample Output 1
1     
  1 2 1   
1 2 3 2 1 

      1       
    1 2 1     
  1 2 3 2 1   
1 2 3 4 3 2 1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // including all the test cases
  int t;
  cin >> t;

  while (t--) {
    int n, i, j;
    cin >> n;

    // iterating over every row
    for (i = 1; i <= n; i++) {
      // preceding blank spaces
      int n_blanks = n - i;
      for (j = 1; j <= n_blanks; j++) {
        cout << "  ";
      }

      // printing the values in ascending order
      int max_val = i;
      for (j = 1; j <= max_val; j++) {
        cout << j << " ";
      }

      // printing the values in descending order
      for (j = max_val - 1; j >= 1; j--) {
        cout << j << " ";
      }

      // succeeding blank spaces
      for (j = 1; j <= n_blanks; j++) {
        cout << "  ";
      }

      // moving printing operation to the next line
      cout << "\n";
    }

    // spacing between different test cases
    cout << "\n";
  }

  return 0;
}

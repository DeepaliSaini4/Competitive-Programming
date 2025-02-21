/*
Description
Given a number N and an array A of N numbers. Print the numbers after sorting them.

Note:
Don't use built-in functions.
Try to solve it with bubble sort algorithm or Selection Sort.

Input Format
The first line contains T, the number of test cases.
For each test case:

The first line contains N, the number of elements.

The second line contains N space-separated integers denoting the array.

Output Format
For each test case, print the numbers after sorting them.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = 0; j < n - i - 1; j++) 
            {
                if (arr[j] > arr[j + 1]) 
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

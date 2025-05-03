/*
You are given an array A of size N, consisting of elements between 1 and N-1, in random order, with only one number being repeated. Find this number.
Try to solve this using O(1) extra space.
*/
#include <bits/stdc++.h>
using namespace std;

// alert!- in this approach orer of elements in the orignial array changes.
int FindRepeated(vector<int> &a)
{  
    int n = a.size();
    sort(a.begin(),a.end());
    int ans = 0;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            ans = a[i];
            break;
        }
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << FindRepeated(a) << "\n";
}
//approach -2 better one
int FindRepeated(vector<int> &a)
{  int n = a.size();
    int _xorele = 0;
    for(int i=0;i<n;i++){
        _xorele^=a[i];
    }
    int _xorall = 0;
    for(int i=1;i<n;i++){
        _xorall ^=i;
    }
     
     return (_xorall^_xorele);
}

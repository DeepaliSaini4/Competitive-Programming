/*
Given two numbers N and M, a 2D array A of size N×M which contains 'x' or '.' only and two numbers X,Y which denote a cell position in A such that 
X is the row number and Y is the column number.
Determine whether all neighbors of the given cell are 'x' or not.
Note: The neighbor cell is any cell that shares an edge or a corner and it should be inside the 2D array.
*/
#include <bits/stdc++.h>
using namespace std;

int valid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        char arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        bool sur = true;
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny, n, m) && arr[nx][ny] == '.')
            {
                sur = false;
                break;
            }
        }
        if (sur)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}

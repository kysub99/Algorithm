#include <bits/stdc++.h>
using namespace std;

int n;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int arr[500][500];
int dp[500][500];

bool isIn(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}

int dfs(int r, int c)
{
    if (dp[r][c] != 0)
    {
        return dp[r][c];
    }
    dp[r][c] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (isIn(nr, nc) && arr[nr][nc] > arr[r][c])
        {
            dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
        }
    }

    return dp[r][c];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res = max(res, dfs(i, j));
        }
    }
    cout << res;
}
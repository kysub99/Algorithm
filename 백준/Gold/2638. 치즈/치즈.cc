#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100][100];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool isIn(int r, int c)
{
    return 0 <= r && r < n && 0 <= c && c < m;
}

int bfs(int r, int c, bool visit[100][100])
{
    int outside = 0;
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = true;
    outside++;
    while (!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (isIn(nr, nc) && arr[nr][nc] == 0 && visit[nr][nc] == false)
            {
                q.push({nr, nc});
                visit[nr][nc] = true;
                outside++;
            }
        }
    }
    return outside;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int res = 0;
    while (1)
    {
        bool visit[100][100] = {false};
        vector<pair<int, int>> melt;
        int outside = bfs(0, 0, visit);
        if (outside == n * m)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == 1)
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (isIn(nr, nc) && visit[nr][nc] == true)
                        {
                            cnt++;
                        }
                    }
                    if (cnt >= 2)
                    {
                        melt.push_back({i, j});
                    }
                }
            }
        }
        for (int i = 0; i < melt.size(); i++)
        {
            int r = melt[i].first;
            int c = melt[i].second;
            arr[r][c] = 0;
        }
        res++;
    }
    cout << res;
}
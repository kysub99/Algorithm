#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[9][9];
int res = 0;
int wallCnt = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void wall(int cnt);
int bfs();
bool isIn(int i, int j);

void wall(int cnt)
{
    if (cnt == 3)
    {
        int virus = bfs();
        res = max(res, n * m - virus - wallCnt - 3);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                wall(cnt + 1);
                arr[i][j] = 0;
            }
        }
    }
}

int bfs()
{
    queue<pair<int, int>> q;
    bool visit[9][9] = {false};
    int virus = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({i, j});
                visit[i][j] = true;
                virus++;
            }
        }
    }
    while (!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextR = curR + dr[i];
            int nextC = curC + dc[i];
            if (isIn(nextR, nextC) && arr[nextR][nextC] == 0 && visit[nextR][nextC] == false)
            {
                q.push({nextR, nextC});
                visit[nextR][nextC] = true;
                virus++;
            }
        }
    }
    return virus;
}

bool isIn(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                wallCnt++;
            }
        }
    }
    wall(0);
    cout << res;
}
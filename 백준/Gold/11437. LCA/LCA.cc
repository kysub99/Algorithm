#include <bits/stdc++.h>
using namespace std;

#define MAX 50001

int n, m;
vector<int> graph[MAX];
bool visited[MAX];
int parent[MAX];
int depth[MAX];

void dfs(int node, int d)
{
    visited[node] = true;
    depth[node] = d;

    for (int next : graph[node])
    {
        if (!visited[next])
        {
            parent[next] = node;
            dfs(next, d + 1);
        }
    }
}

int lca(int a, int b)
{
    while (depth[a] > depth[b])
    {
        a = parent[a];
    }
    while (depth[b] > depth[a])
    {
        b = parent[b];
    }
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
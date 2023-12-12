#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 10'001

int v, e;
vector<pair<int,int>> graph[MAX];//정점, 가중치
bool visit[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e;
    int a, b, c;
    for (int i = 0;i < e;i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;// 가중치, 정점
    pq.push({ 0, 1 });
    int res = 0;
    while (!pq.empty()) {
        int curEdge = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (visit[curNode]) {
            continue;
        }
        res += curEdge;
        visit[curNode] = true;
        for (int i = 0;i < graph[curNode].size();i++) {
            int nextNode = graph[curNode][i].first;
            int nextEdge = graph[curNode][i].second;
            if (!visit[nextNode]) {
                pq.push({ nextEdge, nextNode });
            }
        }
    }
    cout << res;
}

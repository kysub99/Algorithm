#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAX 101

int n;
pair<double, double> graph[MAX];// x, y 좌표
bool visit[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    double x, y;
    for (int i = 0;i < n;i++) {
        cin >> x >> y;
        graph[i].first = x;
        graph[i].second = y;
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;// 가중치, 정점 index
    pq.push({ 0, 0 });
    double res = 0;
    while (!pq.empty()) {
        double curEdge = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        if (visit[curNode])
            continue;
        res += curEdge;
        visit[curNode] = true;
        for (int i = 0;i < n;i++) {
            if (i != curNode && !visit[i]) {
                double curx = graph[curNode].first;
                double cury = graph[curNode].second;
                double nextx = graph[i].first;
                double nexty = graph[i].second;
                double dis = sqrt(pow((curx - nextx), 2) + pow((cury - nexty), 2));
                pq.push({ dis, i });
            }
        }
    }
    cout << res;
}

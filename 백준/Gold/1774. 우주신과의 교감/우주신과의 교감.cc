#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MAX 1'001

int n, m;
int visit[MAX];
pair<int,int> xy[MAX];
bool graph[MAX][MAX];

int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 1;i <= n;i++) {
        cin >> x >> y;
        xy[i].first = x;
        xy[i].second = y;
    }
    int a, b;
    for (int i = 0;i < m;i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    priority_queue <pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;//거리, 우주선 인덱스
    pq.push({ 0,1 });
    double res = 0;
    while (!pq.empty()) {
        double curDis = pq.top().first;
        int curIdx = pq.top().second;
        pq.pop();
        if (visit[curIdx])
            continue;
        visit[curIdx] = true;
        res += curDis;
        for (int i = 1;i <= n;i++) {
            if (!visit[i]) {
                double dis;
                if (graph[curIdx][i])
                    dis = 0;
                else {
                    int curx = xy[curIdx].first;
                    int cury = xy[curIdx].second;
                    int nextx = xy[i].first;
                    int nexty = xy[i].second;
                    dis = sqrt(pow(curx - nextx, 2) + pow(cury - nexty, 2));
                }
                pq.push({ dis, i });
            }
        }
    }
    printf("%.2f", res);
}

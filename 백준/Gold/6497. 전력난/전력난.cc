//프림
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <tuple>
using namespace std;
#define MAX 200'000

int m, n;
vector<int> root(MAX);

int Find(int x) {
    if (x == root[x])
        return x;
    return root[x] = Find(root[x]);
}

void Union(int a, int b) {
    int aLeader = Find(a);
    int bLeader = Find(b);
    root[bLeader] = aLeader;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        priority_queue <tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;// 간선, a, b
        int all = 0;
        int res = 0;
        cin >> m >> n;
        if (!m && !n)
            break;
        for (int i = 0;i < m;i++) {
            root[i] = i;
        }
        for (int i = 0;i < n;i++) {
            int x, y, z;
            cin >> x >> y >> z;
            pq.push({ z,x,y });
            all += z;
        }
        while (!pq.empty()) {
            int x, y, z;
            tie(z, x, y) = pq.top();
            pq.pop();
            if (Find(x) == Find(y))
                continue;
            res += z;
            Union(x, y);
        }
        cout << all-res << "\n";
    }

}

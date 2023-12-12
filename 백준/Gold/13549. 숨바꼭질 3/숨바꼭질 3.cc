#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
#define MAX 100001

int res[MAX];
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    queue<int> q;
    q.push(n);
    res[n] = 1;
    while (!q.empty()) {
        int temp = q.front();
        if (temp == k)
            break;
        q.pop();
        if (2 * temp < MAX && res[2 * temp] == 0) {
            res[2 * temp] = res[temp];
            q.push(2 * temp);
        }
        if (0 <= temp - 1 && res[temp - 1] == 0) {
            res[temp - 1] = res[temp] + 1;
            q.push(temp - 1);
        }
        if (temp + 1 < MAX && res[temp + 1] == 0) {
            res[temp + 1] = res[temp] + 1;
            q.push(temp + 1);
        }
    }
    cout << res[k] - 1;
}

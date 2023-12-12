#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 500'000

int n, m;
int root[MAX];

int Find(int x) {
    if (root[x] == x)
        return x;
    return root[x] = Find(root[x]);
}

bool Combine(int a, int b) {
    int aLeader = Find(a);
    int bLeader = Find(b);
    root[bLeader] = aLeader;
    if (aLeader == bLeader)
        return true;
    else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0;i < n;i++)
        root[i] = i;
    int a, b;
    int res = 0;
    int cnt = 0;
    for (int i = 1;i <= m;i++) {
        cin >> a >> b;
        int isEnd = Combine(a, b);
        if (isEnd && !cnt) {
            res = i;
            cnt++;
        }
    }
    cout << res;
}

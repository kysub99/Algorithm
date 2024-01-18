#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int n, m;
vector<int> xarr;
int maxDis = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    xarr.resize(m);
    for (int i = 0;i < m;i++) {
        cin >> xarr[i];
    }
    for (int i = 0;i < m - 1;i++) {
        maxDis = max(maxDis, xarr[i + 1] - xarr[i]);
    }
    int h = (maxDis + 1) / 2;
    h = max({ h,xarr[0], n - xarr[m - 1] });
    cout << h;

    return 0;
}
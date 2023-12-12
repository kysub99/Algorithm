#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> arr;

long long divide(int l, int r) {
    if (l == r) {
        return arr[l];
    }
    long long m = (l + r) / 2;
    long long lw = divide(l, m);
    long long rw = divide(m + 1, r);
    long long li = m;
    long long ri = m + 1;
    long long h = min(arr[li], arr[ri]);
    long long cw = 2 * h;
    while (l < li || ri < r) {
        if (ri < r && (l == li || arr[li - 1] < arr[ri + 1])) {
            ri++;
            h = min(h, arr[ri]);
        } else {
            li--;
            h = min(h, arr[li]);
        }
        cw = max(cw, h * (ri - li + 1));
    }
    long long maxW = max({lw, cw, rw});
    return maxW;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            return 0;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long res = divide(0, n - 1);
        cout << res << "\n";
    }
}

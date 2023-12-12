#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> arr;
int k, n;
ll res = 0;

void search(ll s, ll e) {
    if (s == e) {
        return;
    }

    ll sum = 0;
    ll m = (s + e) / 2;
    for (int i = 0; i < k; i++) {
        sum += arr[i] / m;
    }

    if (sum >= n) {
        res = max(res, m);
        search(m + 1, e);
    }
    else {
        search(s, m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;

    int maxVal = 0;
    arr.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    search(0, ll(maxVal)+1);
    cout << res << "\n";
}

#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<long long, int> cnt;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        cnt[x]++;
    }

    long long ans = 0;
    int maxCnt = 0;

    for (auto& p : cnt) {
        if (p.second > maxCnt || (p.second == maxCnt && p.first < ans)) {
            ans = p.first;
            maxCnt = p.second;
        }
    }

    cout << ans << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;
int n, m;
vector<ll> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    ll minNum = 1e9;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        minNum = min(minNum, arr[i]);
    }
    ll l = 1;
    ll r = minNum * m;
    ll res = 0;

    while (l <= r) {
        ll mid = (l + r) / 2;

        ll cnt = 0; // mid시간에 검사 가능한 사람수
        for (int i = 0;i < n;i++) {
            cnt += mid / arr[i];
        }
        if (cnt >= m) {// 인원보다 더 검사 가능 -> 시간 줄여도 됨 
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res;
}

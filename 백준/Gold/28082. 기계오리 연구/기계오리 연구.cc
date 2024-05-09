#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);

    // DP 테이블 초기화
    vector<int> dp(sum + 1, INF);
    dp[0] = 0;

    for (int b : arr) {
        for (int s = sum; s >= b; --s) {            
            dp[s] = min(dp[s], dp[s - b] + 1);
        }
    }

    vector<int> res;
    for (int i = 1;i <= sum;i++) {
        if (dp[i] <= k)
            res.push_back(i);
    }

    cout << res.size() << "\n";
    for (int num : res) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
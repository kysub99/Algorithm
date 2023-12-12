#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];
int arr[10001];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]));
    }

    cout << dp[n];
}

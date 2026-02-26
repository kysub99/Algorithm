#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dp[10001];
    int arr[10001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res;
}
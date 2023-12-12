#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    vector<int> arr(1000001);
    for (int i = 2;i <= 1000000;i++) {
        arr[i] = i;
    }
    for (int i = 2;i <= 1000000;i++) {
        if (arr[i] == 0)
            continue;
        for (int j = 2 * i;j <= 1000000;j += i) {
            arr[j] = 0;
        }
    }
    while (t--) {
        cin >> n;  
        int cnt = 0;
        for (int i = 2;i < n;i++) {
            if (arr[i] + arr[n - i] == n)
                cnt++;
            if (i == n - i)
                cnt++;
        }
        cout << cnt/2 << "\n";
    }
}


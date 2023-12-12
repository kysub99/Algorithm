#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        int a, b;
        for (int i = 0;i < m;i++) {
            cin >> a >> b;
        }
        cout << n - 1 << "\n";
    }
}

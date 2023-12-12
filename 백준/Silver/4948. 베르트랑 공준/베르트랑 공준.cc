#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        vector<int> arr(2 * n + 1);
        for (int i = 2;i <= 2 * n;i++) {
            arr[i] = i;
        }
        for (int i = 2;i <= 2 * n;i++) {
            if (arr[i] == 0)
                continue;
            for (int j = 2 * i;j <= 2 * n;j += i) {
                arr[j] = 0;
            }
        }
        int  cnt = 0;
        for (int i = n + 1;i <= 2 * n;i++) {
            if (arr[i] != 0)
                cnt++;
        }
        cout << cnt << "\n";
    }
}

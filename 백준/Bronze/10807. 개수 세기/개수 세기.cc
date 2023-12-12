#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, v;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cin >> v;
    int cnt = 0;
    for (int i : arr) {
        if (i == v)
            cnt++;
    }
    cout << cnt;
}
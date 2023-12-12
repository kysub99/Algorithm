#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    for (long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr(n + 1);
    for (int i = 2;i <= n;i++) {
        arr[i] = i;
    }
    for (int i = 2;i <= n;i++) {
        if (arr[i] == 0)
            continue;
        for (int j = 2 * i;j <= n;j+=i) {
            arr[j] = 0;
        }
    }
    for (int i = m;i <= n;i++) {
        if (arr[i] != 0)
            cout << i << "\n";
    }
}

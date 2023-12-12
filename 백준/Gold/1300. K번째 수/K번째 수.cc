#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long n, k;
long long res = 0;

void divide(long long s, long long e) {
    if (s >= e)
        return;
    long long mid = (s + e) / 2;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        long long temp = min(n, mid / i); // mid보다 작은거나 같은거 개수
        sum += temp;
    }
    /*if (sum == k) {
        res = mid;
        return;
    }*/
    if (sum >= k) {
        res = mid;
        divide(s, mid);
    }
    else {
        divide(mid + 1, e);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    divide(0, k + 1);
    cout << res;
}

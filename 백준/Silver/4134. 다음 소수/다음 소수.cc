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
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        while (true) {
            if (isPrime(n)) {
                cout << n << "\n";
                break;
            }
            else {
                n++;
            }
        }
    }
    return 0;
}

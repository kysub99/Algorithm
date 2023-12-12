#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000

int n;
long long b;
int arr[5][5];
int com[5][5];
int temp[5][5];

/*void mul2(int (*aa)[5]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
            for (int k = 0; k < n; k++) {
                arr[i][j] += (temp[i][k] * aa[k][j]) % MOD;
                arr[i][j] %= MOD;
            }
        }
    }
}*/

void mul(int A[][5], int B[][5]) {
    int C[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += (A[i][k] * B[k][j]) % MOD;
                C[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = C[i][j];
        }
    }
}

void div(long long num) {
    if (num == 1) {
        return;
    } else if (num % 2 == 0) {
        div(num / 2);
        mul(arr, arr);
    } else {
        div(num / 2);
        mul(arr, arr);
        mul(arr, com);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            com[i][j] = arr[i][j];
        }
    }
    div(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] % MOD << " ";
        }
        cout << "\n";
    }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<long long> arr;
long long arrSum = 0;
long long maxNum = 0;

long long getCnt(long long mid) {
    long long cnt = 1;
    long long sum = arr[0];
    for (int i = 1;i < n;i++) {
        if (sum + arr[i] <= mid) {
            sum += arr[i];
        }
        else {
            cnt++;
            sum = arr[i];
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
        arrSum += arr[i];
    }
    long long l = maxNum;
    long long r = arrSum;
    long long res;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if(getCnt(mid)<=m){
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        }       
    }
    cout << res;
}

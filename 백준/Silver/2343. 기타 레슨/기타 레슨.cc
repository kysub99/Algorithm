#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<long long> arr;

// 블루레이의 최대 크기로 나누어 블루레이 개수를 반환하는 함수
long long getCnt(long long mid) {
    long long cnt = 1; // 최소한 하나의 블루레이는 있어야 함
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        if (sum + arr[i] > mid) { // sum이 mid를 초과하면
            cnt++; // 새로운 블루레이가 필요
            sum = arr[i]; // 새로운 블루레이 시작
        }
        else {
            sum += arr[i]; // 현재 블루레이에 추가
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(n);

    long long maxSum = 0; // 전체 합계
    long long maxVal = 0; // 가장 큰 요소

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxSum += arr[i]; // 전체 합계 계산
        maxVal = max(maxVal, arr[i]); // 가장 큰 요소 추적
    }

    long long l = maxVal; // 최소 크기는 가장 큰 요소
    long long r = maxSum; // 최대 크기는 전체 합계
    long long res = maxSum; // 초기 최대 크기

    while (l <= r) {
        long long mid = (l + r) / 2; // 이진 탐색의 중간값

        if (getCnt(mid) <= m) { // 블루레이 개수가 m 이하라면
            res = mid; // 가능한 최대 크기
            r = mid - 1; // 크기를 줄이기 위해 범위 축소
        }
        else {
            l = mid + 1; // 크기를 늘리기 위해 범위 확대
        }
    }

    cout << res; // 블루레이의 최대 크기 출력
}

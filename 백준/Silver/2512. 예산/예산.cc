#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define INF (int)1e9+1

int n, m;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n);
    int start = 0;
    int end = 0;
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
        end = max(end, arr[i]);
    }   
    cin >> m;
    
    int res = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int sum = 0;
        for (int val : arr) {
            sum += min(mid,val);
        }
        
        if (sum <= m) {
            res = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }        
    }

    cout << res;

    return 0;
}
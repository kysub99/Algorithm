#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    for (int tc = 1;tc <= 10;tc++) {
        int n;
        cin >> n;
        vector<int> arr(n + 4, 0);
        for (int i = 2;i < n + 2;i++) {
            cin >> arr[i];
        }
 
        int res = 0;
        for (int i = 2;i < n + 2;i++) {
            int mh = max({ arr[i - 2], arr[i - 1], arr[i + 1], arr[i + 2] });
            res += max(0, arr[i] - mh);         
        }
 
        printf("#%d %d\n", tc, res);
    }
}
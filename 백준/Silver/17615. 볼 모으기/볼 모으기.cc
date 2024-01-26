#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define INF 1e9

int n;
string ball;

int getCnt(char c) {
    bool flag = false;
    int toL = 0;
    int toR = 0;
    for (int i = 0;i < n;i++) {
        if (flag) {
            if (ball[i] == c)
                toL++;
        }
        else {
            if (ball[i] != c)
                flag = true;
        }
    }
    flag = false;    
    for (int i = n - 1;i >= 0;i--) {
        if (flag) {
            if (ball[i] == c)
                toR++;
        }
        else {
            if (ball[i] != c)
                flag = true;
        }
    }
    return min(toL, toR);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> ball;

    cout << min(getCnt('R'), getCnt('B'));

    return 0;
}
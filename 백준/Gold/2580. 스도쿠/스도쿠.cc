#include <iostream>
#include <vector>
using namespace std;

int board[10][10];
vector<pair<int, int>> bk;
int msize;
bool findAnswer = false;

void func(int d) {
    if (d == msize) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++)
                cout << board[i][j] << " ";
            cout << "\n";
        }
        findAnswer = true;
        return;
    } else {
        bool v1[10] = {false};
        bool v2[10] = {false};
        bool v3[10] = {false};

        for (int i = 1; i <= 9; i++) {
            v1[board[bk[d].first][i]] = true;
            v2[board[i][bk[d].second]] = true;
        }
        int itemp = bk[d].first;
        int jtemp = bk[d].second;
        while (itemp % 3 != 1)
            itemp--;
        while (jtemp % 3 != 1)
            jtemp--;
        for (int i = itemp; i < itemp + 3; i++) {
            for (int j = jtemp; j < jtemp + 3; j++)
                v3[board[i][j]] = true;
        }
        for (int i = 1; i <= 9; i++) {
            if (!v1[i] && !v2[i] && !v3[i]) {
                board[bk[d].first][bk[d].second] = i;
                func(d + 1);
                if (findAnswer) return;

                board[bk[d].first][bk[d].second] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0)
                bk.push_back({i, j});
        }
    }
    msize = bk.size();
    func(0);
}

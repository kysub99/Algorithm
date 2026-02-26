#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;
    int l = n / 2;
    vector<int> down(l), up(l), way(h + 1);
    for (int i = 0; i < l; i++)
    {
        cin >> down[i] >> up[i];
    }
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    int res = n;
    int cnt = 0;
    for (int i = 1; i <= h; i++)
    {
        int cd = down.end() - lower_bound(down.begin(), down.end(), i);
        int cu = up.end() - lower_bound(up.begin(), up.end(), h - i + 1);
        int crash = cd + cu;
        if (crash < res)
        {
            res = crash;
            cnt = 1;
        }
        else if (crash == res)
        {
            cnt++;
        }
    }
    cout << res << " " << cnt;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }

    int res = 0;
    while (pq.size() > 1)
    {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        res += n1 + n2;
        pq.push(n1 + n2);
    }
    cout << res;
}
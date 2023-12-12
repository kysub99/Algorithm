#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1001
#define MOD int(1e9+7)

typedef long long ll;

ll n, m;
ll node[MAX + 1];
ll lChild[MAX];
ll rChild[MAX];
ll dp[2001][2001];
vector<ll> arr;


ll nCr(int n, int r) {
	if (n == r || r == 0)
		return 1;
	if (dp[n][r] == 0)
		return dp[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % MOD;
	else
		return dp[n][r];
}

void dfs(ll num) {
	if (lChild[num] != -1)
		dfs(lChild[num]);

	arr.push_back(num);

	if (rChild[num] != -1)
		dfs(rChild[num]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1;i <= n;i++) {
		cin >> node[i] >> lChild[i] >> rChild[i];
	}

	arr.push_back(0);
	dfs(1);
	arr.push_back(n + 1);
	node[0] = 0;
	node[n + 1] = m + 1;

	ll cnt = 1;
	ll res = 1;
	ll tempPrev = 0;

	for (int i = 1;i < arr.size() - 1;i++) {
		ll prev = node[arr[i - 1]];
		ll cur = node[arr[i]];
		ll next = node[arr[i + 1]];
		if (cur == -1) {//현재 노드 모를 때만
			if (prev != -1) {//앞의 노드 알고있음
				tempPrev = prev;
			}
			if (next == -1) {//다음 노드 모름
				cnt++;
			}
			else {//다음 노드 알고있음
				ll range = next - tempPrev - 1;
				ll temp = nCr(range, cnt);
				res = (res * temp) % MOD;
				cnt = 1;
			}
		}
	}

	cout << res;
}
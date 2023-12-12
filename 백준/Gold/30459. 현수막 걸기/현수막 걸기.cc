#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;

int n, m, r;
vector<double> bot, wid, hei;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;
	bot.resize(n);
	hei.resize(m);
	for (int i = 0;i < n;i++)
		cin >> bot[i];
	for (int i = 0;i < m;i++)
		cin >> hei[i];
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			wid.push_back(abs(bot[j] - bot[i]));
		}
	}

	sort(wid.begin(), wid.end());
	sort(hei.begin(), hei.end());

	double maxr = -1;
	for (int i = 0;i < wid.size();i++) {
		double newh = r / (wid[i] / 2);
		int idx = upper_bound(hei.begin(), hei.end(), newh) - hei.begin();
		if (idx != 0) {
			idx--;
			double newr = wid[i] * hei[idx] / 2;
			if (newr > maxr)
				maxr = newr;
		}
	}
	if (maxr == -1)
		cout << -1;
	else {
		cout << fixed << setprecision(1) << maxr;
	}
}
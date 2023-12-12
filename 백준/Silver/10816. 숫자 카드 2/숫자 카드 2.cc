#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	int num;
	map<int, int> mp;
	for (int i = 0;i < n;i++) {
		cin >> num;
		mp[num]++;
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> num;
		cout << mp[num] << " ";
	}
	cout << "\n";
}
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	map<string, int> mp;
	for (int i = 0;i < n;i++) {
		string str;
		cin >> str;
		if (str == "ENTER")
			mp.clear();
		else {
			if (mp[str] == 0) {
				res++;
				mp[str]++;
			}
		}
	}
	cout << res;
}
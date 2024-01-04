#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int n;
string s1, s2, s3;
bool hasRes;

bool test() {
	vector<int> alp(26, 0);
	vector<int> cnt3(26, 0);
	for (int i = 0;i < s1.length();i++) {
		alp[s1[i] - 'a']++;
	}
	for (int i = 0;i < s2.length();i++) {
		alp[s2[i] - 'a']++;
	}
	for (int i = 0;i < s3.length();i++) {
		alp[s3[i] - 'a']--;
	}
	for (int i = 0;i < 26;i++) {
		if (alp[i] != 0) {
			return false;
		}
	}
	return true;
}

void dfs(int i1, int i2, int i3) {
	if (hasRes)
		return;
	if (i3 == s3.length()) {
		hasRes = true;
		return;
	}	

	if (i1 < s1.length()&&s1[i1] == s3[i3]) {
		dfs(i1 + 1, i2, i3 + 1);
	}
	if (i2 < s2.length()&&s2[i2] == s3[i3]) {
		dfs(i1, i2 + 1, i3 + 1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> s1 >> s2 >> s3;
		
		hasRes = false;
		if (test())
			dfs(0, 0, 0);
		cout << "Data set " << i << ": ";
		if (hasRes)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
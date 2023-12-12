#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define MAX 1'000'001

string t, p;
int n, m;
int ff[MAX];
vector<int> idx;
int cnt = 0;

void setFail() {
	int i = 1;
	int j = 0;
	while (i < m) {
		if (p[i] == p[j]) {
			ff[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = ff[j - 1];
		}
		else {
			ff[i] = 0;
			i++;
		}
	}
}

void kmp() {
	setFail();
	int i = 0;
	int j = 0;
	while (i < n) {
		if (t[i] == p[j]) {
			if (j == m - 1) {
				cnt++;
				idx.push_back(i - j + 1);
				if (j > 0) {
					j = ff[j - 1];
				}
				else {
					i++;
					j = 0;
				}
			}
			else {
				i++;
				j++;
			}
		}
		else if (j > 0) {
			j = ff[j - 1];
		}
		else {
			i++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, t);
	getline(cin, p);
	n = t.length();
	m = p.length();
	kmp();
	cout << cnt << "\n";
	for (int val : idx) {
		cout << val << "\n";
	}
}
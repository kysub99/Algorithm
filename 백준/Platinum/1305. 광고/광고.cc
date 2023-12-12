#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 1'000'001

int l;
string str;
int ff[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> l >> str;

	int n = str.size();
	int m = str.size();
	int i = 1;
	int j = 0;
	ff[0] = 0;
	while (i < n) {
		if (str[i] == str[j]) {
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
	/*for (int i = 0;i < n;i++) {
		cout << ff[i] << " ";
	}*/
	cout << n - ff[n - 1];
}
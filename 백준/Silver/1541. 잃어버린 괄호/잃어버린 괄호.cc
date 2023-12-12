#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	string str;
	cin >> str;
	vector<int> narr;
	vector<char> sarr;
	sarr.push_back('n');
	vector<char> temp[50];
	
	int cnt = 0;//부호 개수, 숫자개수-1
	for (int i = 0;i < str.size();i++) {
		if (str[i] == '+' || str[i] == '-') {
			sarr.push_back(str[i]);
			cnt++;
		}
		else {
			temp[cnt].push_back(str[i]);
		}
	}
	
	for (int i = 0;i < cnt + 1;i++) {
		int tnum=0;
		for (int j = 0;j < temp[i].size();j++) {
			tnum += pow(10, temp[i].size() - j - 1) * (temp[i][j]-'0');
		}
		narr.push_back(tnum);
	}
	bool check = false;
	int res = narr[0];
	for (int i = 1;i < cnt + 1;i++) {
		if (check) {
			res -= narr[i];
		}
		else {
			if (sarr[i] == '-') {
				check = true;
				res -= narr[i];
			}
			else {
				res += narr[i];
			}
		}
	}
	cout << res << "\n";
}
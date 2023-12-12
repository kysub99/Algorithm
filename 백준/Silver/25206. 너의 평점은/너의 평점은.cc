#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string sub, grade;
	double cred;
	double all = 0;
	double mul = 0;
	for (int i = 0;i < 20;i++) {
		cin >> sub >> cred >> grade;
		if (grade == "P")
			continue;
		all += cred;
		if (grade == "A+")
			mul += cred * 4.5;
		else if (grade == "A0")
			mul += cred * 4.0;
		else if (grade == "B+")
			mul += cred * 3.5;
		else if (grade == "B0")
			mul += cred * 3.0;
		else if (grade == "C+")
			mul += cred * 2.5;
		else if (grade == "C0")
			mul += cred * 2.0;
		else if (grade == "D+")
			mul += cred * 1.5;
		else if (grade == "D0")
			mul += cred * 1.0;
	}
	cout << mul / all;
}
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	cout << ((s[0] == 'I') ? 'E' : 'I');
	cout << ((s[1] == 'N') ? 'S' : 'N');
	cout << ((s[2] == 'T') ? 'F' : 'T');
	cout << ((s[3] == 'P') ? 'J' : 'P');
}
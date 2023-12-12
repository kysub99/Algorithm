#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	string name;
	map<string, int> nti;
	map<int, string> itn;
	for (int i = 1;i <= n;i++) {
		cin >> name;
		nti.insert({ name,i });
		itn.insert({ i,name });
	}
	for (int i = 0;i < m;i++) {
		string str;
		cin >> str;
		if ('0' <= str[0] && str[0] <= '9') {
			int temp = stoi(str);
			cout << itn[temp] << "\n";
		}
		else {
			cout << nti[str] << "\n";
		}
	}
}
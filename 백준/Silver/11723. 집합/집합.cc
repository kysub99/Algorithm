#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m;
int s = 0;

bool Check(int x) {
	if (((s >> x) & 1) == 1)
		return true;
	else
		return false;
}

void Toggle(int x) {
	s ^= (1 << x);
}

void Add(int x) {
	if (!Check(x))
		Toggle(x);
}

void Remove(int x) {
	if (Check(x))
		Toggle(x);
}

void All() {
	s = (1 << 21) - 1;
}

void Empty() {
	s = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m;
	string str;
	int x;
	while (m--) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			Add(x);
		}
		else if (str == "remove") {
			cin >> x;
			Remove(x);
		}
		else if (str == "check") {
			cin >> x;
			if (Check(x))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "toggle") {
			cin >> x;
			Toggle(x);
		}
		else if (str == "all"){
			All();
		}
		else if (str == "empty") {
			Empty();
		}

	}
}
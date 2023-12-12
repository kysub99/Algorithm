#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int n, k;
string str;

class Trie {
public:
	map<string, Trie*> child;
};

Trie* root = new Trie;

void Insert(vector<string>& arr) {
	Trie* cur = root;
	for (int i = 0;i < arr.size();i++) {
		if (cur->child.find(arr[i]) == cur->child.end()) {//없음
			Trie* newTrie = new Trie;
			cur->child.insert({ arr[i], newTrie });
		}
		cur = cur->child[arr[i]];
	}
}

void Print(Trie* node, int d) {
	for (auto& i : node->child) {
		for (int j = 0;j < d;j++) {
			cout << "--";
		}
		cout << i.first << "\n";
		Print(i.second, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	
	for (int i = 0;i < n;i++) {
		cin >> k;
		vector<string> arr(k);
		for (int j = 0;j < k;j++) {
			cin >> arr[j];
		}
		Insert(arr);
	}
	Print(root, 0);
}
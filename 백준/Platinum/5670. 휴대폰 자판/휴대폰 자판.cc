#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define ALP 26

int t, n;

int cti(char c) {
	return c - 'a';
}

class Trie {
private:
	Trie* child[ALP];
	bool isIn;// 해당 문자가 있는지
	int cnt;// 자식 노드 개수

public:
	Trie() {
		for (int i = 0;i < ALP;i++) {
			child[i] = nullptr;
		}
		isIn = false;
		cnt = 0;
	}
	~Trie() { 
		for (int i = 0; i < ALP; ++i) {
			if (child[i]) 
				delete child[i];
		}
	}
	void Insert(string str) {
		Trie* temp = this;
		for (int i = 0;i < str.size();i++) {
			int idx = cti(str[i]);
			if (temp->child[idx] == nullptr) {//해당 문자 없음
				temp->child[idx] = new Trie();
				temp->cnt++;//자식 노드 개수 늘림
			}
			temp = temp->child[idx];
		}
		temp->isIn = true;//해당 문자열 있음 표시
	}

	double Find(string str) {
		double res = 0;
		Trie* temp = this;
		for (int i = 0;i < str.size();i++) {
			int idx = cti(str[i]);
			if (temp->cnt > 1 || temp->isIn || temp == this) {//자식이 하나 이상이거나, 문자열이 있거나 루트
				res++;
			}
			temp = temp->child[idx];
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> n) {
		Trie* root = new Trie();
		vector<string> arr(n);
		for (int i = 0;i < n;i++) {
			cin >> arr[i];
			root->Insert(arr[i]);
		}
		double res = 0;
		for (int i = 0;i < n;i++) {
			res += root->Find(arr[i]);
		}
		res /= n;
		res = round(res * 100);
		res /= 100;
		cout << fixed;
		cout.precision(2);
		cout << res << "\n";
		delete root;
	}
}
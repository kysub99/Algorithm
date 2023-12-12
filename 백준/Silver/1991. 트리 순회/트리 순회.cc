#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
#define MAX 26

int n;
pair<int, int> tree[26];

int cti(char c) {
	return c - 'A';
}

char itc(int i) {
	return i + 'A';
}

void preorder(int i) {
	cout << itc(i);
	int left = tree[i].first;
	int right = tree[i].second;
	if (left != -1)
		preorder(left);
	if (right != -1)
		preorder(right);
}

void inorder(int i) {
	int left = tree[i].first;
	int right = tree[i].second;
	if (left != -1)
		inorder(left);
	cout << itc(i);
	if (right != -1)
		inorder(right);
}

void postorder(int i) {
	int left = tree[i].first;
	int right = tree[i].second;
	if (left != -1)
		postorder(left);
	if (right != -1)
		postorder(right);
	cout << itc(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	char a, b, c;
	for (int i = 0;i < n;i++) {
		cin >> a >> b >> c;
		int par = cti(a);
		if (b == '.')
			tree[par].first = -1;
		else
			tree[par].first = cti(b);
		if (c == '.')
			tree[par].second = -1;
		else
			tree[par].second = cti(c);
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	cout << "\n";
}
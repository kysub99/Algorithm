#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100'001

int n;
int inOrder[MAX];
int postOrder[MAX];
int inIdx[MAX];

void preOrder(int ins, int ine, int posts, int poste) {
	if (ins > ine || posts > poste)
		return;
	cout << postOrder[poste] << " ";
	int eIdx = inIdx[postOrder[poste]];
	int flen = eIdx - ins;//앞부분 길이
	preOrder(ins, eIdx - 1, posts, posts + flen - 1);
	preOrder(eIdx + 1, ine, posts + flen, poste - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> inOrder[i];
		inIdx[inOrder[i]] = i;// 입력받은 노드는 inOrder의 i번째 인덱스에 있음
	}
	for (int i = 1;i <= n;i++) {
		cin >> postOrder[i];
	}
	preOrder(1, n, 1, n);
}
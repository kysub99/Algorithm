#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> node;

void postOrder(int start, int end) {
	if (start == end) {
		cout << node[start] << "\n";
		return;
	}
	else if (start > end)
		return;
	int root = start;
	int idx;
	for (idx = start;idx <= end;idx++) {
		if (node[root] < node[idx])
			break;
	}
	postOrder(root + 1, idx - 1);
	postOrder(idx, end);
	cout << node[root] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n) {
		node.push_back(n);
	}
	int nodeEnd = node.size()-1;
	postOrder(0, nodeEnd);
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
int md = 0;
int max_res = -1e9;
int min_res = 1e9; void func(int d, vector<int> arr, int* op, vector<int> op_res) {
	if (md == d) {
		int sum = arr[0];
		for (int i = 0; i < op_res.size();i++) {
			if (op_res[i] == 0)
				sum += arr[i + 1];
			else if (op_res[i] == 1)
				sum -= arr[i + 1];
			else if (op_res[i] == 2)
				sum *= arr[i + 1];
			else
				sum /= arr[i + 1];
		}
		max_res = max(max_res, sum);
		min_res = min(min_res, sum);
	}
	else {
		for (int i = 0;i < 4;i++) {
			if (op[i] != 0) {
				op_res[d] = i;
				op[i]--;
				func(d + 1, arr, op, op_res);
				op[i]++;
			}
		}
	}
} int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	int op[4];// + - * /
	for (int i = 0;i < 4;i++) {
		cin >> op[i];
		md += op[i];
	}
	vector<int> op_res(md);
	func(0, arr, op, op_res);
	cout << max_res << "\n";
	cout << min_res << "\n";
}
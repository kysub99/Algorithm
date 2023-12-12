#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class pq {
private:
	int arr[100001];
	int size;
	int top;
public:
	pq() {
		size = 0;
	}
	bool empty() {
		return (size == 0);
	}
	void insert(int num) {
		size++;
		int idx = size;
		arr[idx] = num;
		while (idx > 1) {
			int par = idx / 2;
			if (abs(arr[idx]) == abs(arr[par])) {
				if (arr[idx] < arr[par]) {
					swap(arr[idx], arr[par]);
					idx = par;
				}
				else
					break;
			}
			else if (abs(arr[idx]) < abs(arr[par])) {
				swap(arr[idx], arr[par]);
				idx = par;
			}
			else {
				break;
			}
		}

	}
	int erase() {
		if (empty())
			return 0;
		int temp = arr[1];
		swap(arr[1], arr[size]);
		size--;
		int idx = 1;
		while (idx * 2 <= size) {
			int left = idx * 2;
			int right = idx * 2 + 1;
			int small = left;
			if (right <= size) {
				if (abs(arr[right]) == abs(arr[left])) {
					if (arr[right] < arr[left])
						small = right;
				}
				else if (abs(arr[right]) < abs(arr[left]))
					small = right;
			}
			if (abs(arr[idx]) == abs(arr[small])) {
				if (arr[idx] > arr[small]) {
					swap(arr[idx], arr[small]);
					idx = small;
				}
				else
					break;
			}
			else if (abs(arr[idx]) > abs(arr[small])) {
				swap(arr[idx], arr[small]);
				idx = small;
			}
			else {
				break;
			}
		}
		return temp;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;
	pq newpq;
	for (int i = 0;i < n;i++) {
		cin >> x;
		if (x)
			newpq.insert(x);
		else
			cout << newpq.erase() << "\n";
	}
}
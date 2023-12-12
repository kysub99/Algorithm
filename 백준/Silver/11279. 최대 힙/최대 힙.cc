#include <iostream>
#include <vector>
#include <algorithm>
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
			if (arr[idx] > arr[par]) {
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
		while (idx*2 <= size) {
			int left = idx * 2;
			int right = idx * 2 + 1;
			int big = left;
			if (right <= size && arr[right] > arr[left])
				big = right;
			if (arr[idx] < arr[big]) {
				swap(arr[idx], arr[big]);
				idx = big;
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
		int num;
		cin >> num;
		if (num)
			newpq.insert(num);
		else
			cout << newpq.erase() << "\n";
	}
}
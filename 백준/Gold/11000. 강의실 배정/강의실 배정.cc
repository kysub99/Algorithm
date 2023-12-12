#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, s, t;
vector<pair<int, int>> arr;//시작시간, 종료시간 저장
priority_queue<int, vector<int>, greater<int>> pq;//강의실 종료시간 오름차순 정렬

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		arr.push_back({ s,t });
	}
	sort(arr.begin(), arr.end());//수업 시작시간 오름차순 정렬
	pq.push(arr[0].second);
	for (int i = 1; i < n; i++) {
		if (arr[i].first >= pq.top())//가장 빠른 종료시간보다 시작시간이 같거나 늦음
			pq.pop();//종료시간 갱신위해 pop
		pq.push(arr[i].second);
	}
	cout << pq.size() << "\n";//큐 사이즈-강의실 수
}
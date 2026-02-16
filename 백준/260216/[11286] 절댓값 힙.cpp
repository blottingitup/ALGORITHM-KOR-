#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<pair<int, int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op) pq.push({ -abs(op), -op });  // 작은 순서대로
		else {
			if (pq.empty()) cout << 0 << "\n";
			else {
				int out = -pq.top().second;  // 원래 숫자 복원
				pq.pop();
				cout << out << "\n";
			}
		}

	}
}
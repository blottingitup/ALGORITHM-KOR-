#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp, sum = 0;
	deque<int> d;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		d.push_back(i + 1);

	for (int i = 0; i < m; i++) {
		cin >> temp;
		int j;
		for (j = 0; j < d.size(); j++)  // 맨 앞으로부터의 거리
			if (d[j] == temp) break;
		if (j >= d.size() / 2 + 1) {  // 거리가 절반 초과면 3번 연산
			for (int k = d.size(); k > j; k--) {
				int t = d.back();
				d.pop_back();
				d.push_front(t);
				sum++;
			}
		}
		else {  // 거리가 절반 이하면 2번 연산
			for (int k = 0; k < j; k++) {
				int t = d.front();
				d.pop_front();
				d.push_back(t);
				sum++;
			}
		}
		d.pop_front();
	}
	cout << sum;
}
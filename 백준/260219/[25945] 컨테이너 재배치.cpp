#include <iostream>
using namespace std;

typedef long long int ll;

int con[1000000];  // ch[i]는 i까지의 증가 후 감소하는 수의 누적 개수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m = 0;
	ll sum = 0;  // 최대 40억까지 저장 가능해야 함
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> con[i];
		m += con[i];
	}
	sort(con, con + n);

	// 가능한 높이는 (m / n) 혹은 (m / n + 1)
	int leftover = m % n, right_h = m / n + 1;  // leftover는 높이가 (m / n + 1)인 칸의 개수
	if (!leftover) right_h--;
	for (int i = n - 1; i >= 0; i--) {
		sum += (ll)(con[i] >= right_h ? con[i] - right_h : right_h - con[i]);
		if (leftover) {
			leftover--;
			if (!leftover) right_h--;
		}
	}
	cout << sum / 2LL;  // 가능한 높이보다 낮은 칸, 높은 칸 중복으로 고려했으므로 2로 나누기
}
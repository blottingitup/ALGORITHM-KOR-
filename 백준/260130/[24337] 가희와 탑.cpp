#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	deque<int> d;
	cin >> n >> a >> b;
	if (a + b > n + 1) cout << -1;  // 가장 큰 탑을 공유한다면 a + b의 최댓값은 n + 1
	else {
		for (int i = b - 1; i > 0; i--)  // 사전순 나열이기 때문에 최대 높이 건물이 최대한 가희쪽에 있도록
			d.push_back(i);
		
		if (a == 1) {  // a = 1인 경우 가장 높은 탑이 맨 왼쪽에 위치
			for (int i = 0; i < n - b; i++)
				d.push_front(1);
			d.push_front(b);
		}
		else {
			d.push_front(max(a, b));
			for (int i = a - 1; i > 0; i--)
				d.push_front(i);
			// 최대한 건물을 오른쪽으로 밀고 왼쪽은 1로 채워 사전순 나열 조건 만족
			for (int i = 0; i < n - a - b + 1; i++)
				d.push_front(1);
		}
		for (int i = 0; i < n; i++)
			cout << d[i] << " ";
	}
}
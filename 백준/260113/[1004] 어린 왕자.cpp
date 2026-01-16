#include <iostream>
using namespace std;

double dist2(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (x2 - x1) + (y2 - y1)* (y2 - y1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x1, y1, x2, y2, n, sum = 0;
		cin >> x1 >> y1 >> x2 >> y2 >> n;
		for (int j = 0; j < n; j++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			// 출발점, 도착점 모두 같은 원 안에 있으면 행성계 내 이동이므로 제외
			if (dist2(x1, y1, cx, cy) < r * r && dist2(x2, y2, cx, cy) < r * r)
				continue;
			// 출발점, 도착점 중 하나만 원 안에 있으면 행성계 간 이동
			else if (dist2(x1, y1, cx, cy) < r * r)
				sum++;
			else if (dist2(x2, y2, cx, cy) < r * r)
				sum++;
		}
		cout << sum << "\n";
	}
}
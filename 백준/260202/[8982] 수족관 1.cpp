#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> depth(40001);
vector<int> hole(40001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, t1[2], t2[2];
	cin >> n >> t1[0] >> t2[0];
	for (int i = 1; i < n; i++) {
		cin >> t1[1] >> t2[1];
		if (t2[1] == t2[0] && t1[1] != t1[0]) {  // depth[i]는 x좌표 i의 깊이 ([i, i + 1))
			for (int j = t1[0]; j < t1[1]; j++)
				depth[j] = t2[1];
		}
		t1[0] = t1[1], t2[0] = t2[1];
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c >> b;
		// 구멍있는 구간은 누수 최대 깊이 = 현재 깊이
		for (int j = a; j < c; j++)
			hole[j] = b;
		// 구멍있는 구간 양 옆으로 누수 최대 깊이 갱신
		int cur_hole = b;
		for (int j = a - 1; j >= 0; j--) {
			cur_hole = min(cur_hole, depth[j]);  // 깊이가 더 얕은 곳에서는 최대 수면 높이가 그 깊이로 고정
			hole[j] = max(hole[j], cur_hole);
		}
		cur_hole = b;
		for (int j = c; j < t1[0]; j++) {
			cur_hole = min(cur_hole, depth[j]);
			hole[j] = max(hole[j], cur_hole);
		}
	}

	int sum = 0;
	for (int i = 0; i < t1[0]; i++)
		sum += max(0, depth[i] - hole[i]);
	cout << sum;
}
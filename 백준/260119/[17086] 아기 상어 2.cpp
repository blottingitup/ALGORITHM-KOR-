#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ter[50][50] = { 0, }, dist[50][50] = { 0, };
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ter[i][j];
			if (ter[i][j]) dist[i][j] = 0;
		}
	}

	vector<pair<int, int>> dir = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ter[i][j]) continue;  // 상어 있는 칸에서는 할 필요 없음
			bool encounter = false, visited[50][50] = { false, };
			queue<pair<int, int>> shark;
			int d = 1, cnt = 1;
			shark.push({ i, j });
			visited[i][j] = true;

			while (!shark.empty()) {  // 상어 조우할 때까지 각 칸에서 BFS
				auto [x, y] = shark.front();
				shark.pop();
				cnt--;
				for (int k = 0; k < 8; k++) {
					auto [xdir, ydir] = dir[k];
					int xx = x + xdir, yy = y + ydir;
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy]) {
						if (ter[xx][yy]) {
							encounter = true;
							dist[i][j] = d;
							break;
						}
						else {
							visited[xx][yy] = true;
							shark.push({ xx, yy });
						}
					}
				}
				if (encounter) break;
				if (!cnt) {
					cnt = shark.size();
					d++;
				}
			}
		}
	}

	int max_safe = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			max_safe = max(max_safe, dist[i][j]);
	cout << max_safe;
}
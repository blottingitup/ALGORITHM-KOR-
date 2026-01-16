#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int m, n, h, tomato[101][101][101];
bool visited[101][101][101];
queue<tuple<int, int, int>> q;

void bfs(int aa, int bb, int cc) {
	if (aa > 0 && aa <= h && bb > 0 && bb <= n && cc > 0 && cc <= m) {
		if (!visited[aa][bb][cc] && !tomato[aa][bb][cc]) {
			q.push({ aa, bb, cc });
			tomato[aa][bb][cc] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int day = 0;
	cin >> m >> n >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)
					q.push({ i, j, k });
			}
		}
	}

	int r = q.size();
	bool end = false;
	vector<pair<int, int>> dir = { { -1, 0 }, {0, 1}, {1, 0}, {0, -1} };
	while (!q.empty()) {
		auto [i, j, k] = q.front();
		if (!visited[i][j][k] && tomato[i][j][k] == 1) {
			visited[i][j][k] = true;
			q.pop();
			r--;
			// BFS
			for (int adir = -1; adir < 2; adir += 2)  // 높이 방향
				bfs(i + adir, j, k);
			for (int odir = 0; odir < 4; odir++)  // 가로, 세로 방향
				bfs(i, j + dir[odir].first, k + dir[odir].second);

			if (!r) {  // 하루마다 r개의 토마토가 주변을 익힌다
				day++;
				r = q.size();
			}
		}
	}
	
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++)
				if (!tomato[i][j][k]) {
					cout << -1;
					return 0;
				}
		}
	}
	cout << day - 1;  // 최초에 익어있는 토마토 제외
}
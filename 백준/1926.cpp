#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, paint, p_size, p_max, canvas[500][500];
vector<pair<int, int>> dir = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
bool visited[500][500];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> canvas[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || !canvas[i][j]) continue;
			visited[i][j] = true;
			q.push({ i, j });  // 가능한 경우 모든 점을 bfs 시작점으로
			p_size = 1;  // 그림 크기 초기화
			while (1) {
				if (q.empty()) {  // 그림 구역 전부 탐색 완료
					if (p_max < p_size) p_max = p_size;
					paint++;
					p_size = 0;
					break;
				}
				auto [x, y] = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					auto [xdir, ydir] = dir[k];
					int xx = x + xdir, yy = y + ydir;
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && canvas[xx][yy] && !visited[xx][yy]) {
						visited[xx][yy] = true;
						q.push({ xx, yy });
						p_size++;  // 인접해있는 칸은 같은 그림 내의 칸이므로 그림 크기 증가
					}
				}
			}
		}
	}
	cout << paint << "\n" << p_max;
}
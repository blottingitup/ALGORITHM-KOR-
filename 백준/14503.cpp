#include <iostream>
#include <utility>
using namespace std;

int n, m, sum, room[50][50];
bool ch[50][50];
pair<int, int> dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void clean(int x, int y, int d) {
	if (!ch[x][y]) {  // 청소 안된 현재 칸은 청소
		ch[x][y] = true;
		sum++;
	}
	// 상하좌우 4방향 탐색
	bool able = false;
	for (int i = 0; i < 4; i++) {
		auto [xdir, ydir] = dir[i];
		if (x + xdir >= 0 && x + xdir < n && y + ydir >= 0 && y + ydir < m && !ch[x + xdir][y + ydir]) {
			able = true;
			break;
		}
	}
	if (able) {  // 청소 가능한 칸이 상하좌우에 존재
		d += 3;  // 반시계 방향 회전
		auto [xdir, ydir] = dir[d % 4];
		// 앞쪽 칸이 청소 안되어 있으면 전진, 아니면 반복
		if (x + xdir >= 0 && x + xdir < n && y + ydir >= 0 && y + ydir < m && !ch[x + xdir][y + ydir])
			clean(x + xdir, y + ydir, d);
		else if (ch[x + xdir][y + ydir])
			clean(x, y, d);
	}
	else {  // 청소 가능한 칸이 상하좌우에 없음
		auto [xdir, ydir] = dir[d % 4];
		// 후진 가능하면 후진, 불가능하면 종료
		if (x - xdir >= 0 && x - xdir < n && y - ydir >= 0 && y - ydir < m && room[x - xdir][y - ydir])
			return;
		else if (!room[x - xdir][y - ydir])
			clean(x - xdir, y - ydir, d);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, d;
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] == 1) ch[i][j] = true;
		}
	}

	clean(r, c, d);
	cout << sum;
}
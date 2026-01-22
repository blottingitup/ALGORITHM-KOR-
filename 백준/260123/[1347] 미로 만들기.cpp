#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int maze[101][101];
int xdir[4] = { 1, 0, -1, 0 };
int ydir[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x = 50, y = 50;
	string s;
	cin >> n >> s;

	maze[x][y] = 1;
	int xmin = 50, ymin = 50, xmax = 50, ymax = 50, xnum = 0, ynum = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'F') {  // 전진
			x += xdir[xnum];
			y += ydir[ynum];
			maze[x][y] = 1;
			xmin = min(xmin, x), ymin = min(ymin, y);  // 좌표 내에서 실제 이동한 최솟값
			xmax = max(xmax, x), ymax = max(ymax, y);  // 좌표 내에서 실제 이동한 최댓값
		}
		else if (s[i] == 'L') {  // 좌회전
			xnum = (xnum + 1) % 4;
			ynum = (ynum + 1) % 4;
		}
		else {  // 우회전
			xnum = (xnum + 3) % 4;
			ynum = (ynum + 3) % 4;
		}
	}

	for (int i = xmin; i <= xmax; i++) {
		for (int j = ymin; j <= ymax; j++) {
			if (maze[i][j]) cout << ".";
			else cout << "#";
		}
		cout << "\n";
	}
}
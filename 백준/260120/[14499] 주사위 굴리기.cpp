#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, y, k, w[20][20], die[7] = { 0, };
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> w[i][j];

	vector<pair<int, int>> dir = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
	for (int i = 0; i < k; i++) {
		int dirnum;
		cin >> dirnum;
		auto [xdir, ydir] = dir[dirnum];
		if (x + xdir < 0 || x + xdir >= n || y + ydir < 0 || y + ydir >= m)
			continue;  // 바깥으로 이동 시 명령 무시

		int temp = die[1];
		switch (dirnum) {  // 주사위를 굴려서 나오는 새로운 전개도
			case 1:  // 동쪽
				die[1] = die[3];
				die[3] = die[6];
				die[6] = die[4];
				die[4] = temp;
				break;
			case 2:  // 서쪽
				die[1] = die[4];
				die[4] = die[6];
				die[6] = die[3];
				die[3] = temp;
				break;
			case 3:  // 북쪽
				die[1] = die[2];
				die[2] = die[6];
				die[6] = die[5];
				die[5] = temp;
				break;
			case 4:  // 남쪽
				die[1] = die[5];
				die[5] = die[6];
				die[6] = die[2];
				die[2] = temp;
		}
		x += xdir, y += ydir;  // 실제 좌표 이동
		if (w[x][y]) {  // 이동한 칸이 0이 아닐 때
			die[1] = w[x][y];  // 주사위로 숫자 옮기고
			w[x][y] = 0;  // 칸의 수가 0이 됨
		}
		else  // 이동한 칸이 0이면
			w[x][y] = die[1];  // 주사위의 숫자를 칸으로 옮긴다

		cout << die[6] << "\n";
	}
}
#include <iostream>
using namespace std;

bool grid[200][200][3];  // grid는 초기 상태의 격자, 1차 폭발, 2차 폭발 격자: 두 형태의 순환

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, n;
	char s;
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> s;
			if (s == 'O') {
				grid[i][j][0] = 1;
				grid[i][j][1] = 1;
			}
		}
	}

	if (!(n % 2)) {  // 짝수에는 전체 격자에 폭탄이 설치되어 있음
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << 'O';
			cout << "\n";
		}
	}
	else if (n == 1) {  // 초기 상태
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j][0]) cout << 'O';
				else cout << '.';
			}
			cout << "\n";
		}
	}
	else {
		// 1차 폭발
		int mode = 1;
		int xdir[4] = { -1, 0, 1, 0 }, ydir[4] = { 0, 1, 0, -1 };
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j][0]) {
					for (int k = 0; k < 4; k++) {
						int xx = i + xdir[k], yy = j + ydir[k];
						if (xx >= 0 && xx < r && yy >= 0 && yy < c)
							grid[xx][yy][1] = 1;
					}
				}
			}
		}

		// 2차 폭발
		if (n % 4 == 1) {
			mode = 2;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (!grid[i][j][1]) {
						grid[i][j][2] = 1;
						for (int k = 0; k < 4; k++) {
							int xx = i + xdir[k], yy = j + ydir[k];
							if (xx >= 0 && xx < r && yy >= 0 && yy < c)
								grid[xx][yy][2] = 1;
						}
					}
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j][mode]) cout << '.';
				else cout << 'O';
			}
			cout << "\n";
		}
	}
}
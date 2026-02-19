#include <iostream>
#include <algorithm>
using namespace std;

int space[6][6], dir[6][6][3];  // 0: 왼쪽에서 / 1: 직선 / 2: 오른쪽에서

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
			if (!i) {
				dir[i][j][0] = space[i][j], dir[i][j][1] = space[i][j], dir[i][j][2] = space[i][j];
			}
			else {
				dir[i][j][0] = 1000, dir[i][j][1] = 1000, dir[i][j][2] = 1000;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = -1; k <= 1; k++) {  // 현재 이동 방향
				if (j == 0 && k == -1 || j == m - 1 && k == 1) continue;
				if (i == 1) dir[i][j][k + 1] = space[i - 1][j + k] + space[i][j];  // 이때는 직전 이동 방향 없음
				else {
					for (int l = -1; l <= 1; l++) {  // 직전 이동 방향
						if (k == l) continue;  // 현재 이동 방향과 직전 이동 방향은 겹치면 안됨
						dir[i][j][k + 1] = min(dir[i][j][k + 1], dir[i - 1][j + k][l + 1] + space[i][j]);
					}
				}
			}
		}
	}

	/*cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "< ";
			for (int k = 0; k < 3; k++)
				cout << dir[i][j][k] << " ";
			cout << " >\t";
		}
		cout << "\n";
	}*/

	int min_fuel = 1000;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 3; j++)
			min_fuel = min(min_fuel, dir[n - 1][i][j]);
	cout << min_fuel;
}
#include <iostream>
#include <algorithm>
using namespace std;

int a[2223][2223], d[2223][2223];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			d[i][j] = INT32_MAX;
		}
	}

	// d는 해당 칸으로 이동하기 위한 총 버튼 누르기 횟수
	d[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i > 1) {  // 세로 방향 이동
				if (a[i][j] >= a[i - 1][j])  // 이동을 위한 버튼 누르기
					d[i][j] = min(d[i][j], d[i - 1][j] + a[i][j] - a[i - 1][j] + 1);
				else d[i][j] = min(d[i][j], d[i - 1][j]);
			}

			if (j > 1) {  // 가로 방향 이동
				if (a[i][j] >= a[i][j - 1])  // 이동을 위한 버튼 누르기
					d[i][j] = min(d[i][j], d[i][j - 1] + a[i][j] - a[i][j - 1] + 1);
				else d[i][j] = min(d[i][j], d[i][j - 1]);
			}
		}
	}
	cout << d[n][n];
}
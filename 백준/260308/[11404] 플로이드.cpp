#include <iostream>
#include <algorithm>
using namespace std;

int bus[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(bus[0], 101 * 101, 1e9);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus[a][b] = min(bus[a][b], c);
	}

	// 대각성분은 0으로 초기화
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) bus[i][j] = 0;

	// 플로이드-워셜
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++)
				bus[j][k] = min(bus[j][k], bus[j][i] + bus[i][k]);
		}
	}

	// 갈 수 없는 경우는 0으로 처리
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (bus[i][j] == (int)1e9) bus[i][j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << bus[i][j] << " ";
		cout << "\n";
	}
}
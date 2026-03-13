#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int arr[21], dp[21][21][21];  // dp[i][j][k]: i번째 순서, 열린 벽장 중 왼쪽 j, 오른쪽 k

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, o1, o2, l;
	cin >> n >> o1 >> o2 >> l;
	for (int i = 0; i < l; i++)
		cin >> arr[i];

	fill(&dp[0][0][0], &dp[0][0][0] + 21 * 21 * 21, 1e9);
	dp[0][o1][o2] = 0;  // 초기 위치
	for (int i = 0; i < l; i++) {
		int next = arr[i];
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// abs(현재 위치 - 열린 위치)만큼 이동
				dp[i + 1][next][k] = min(dp[i + 1][next][k], dp[i][j][k] + abs(next - j));
				dp[i + 1][j][next] = min(dp[i + 1][j][next], dp[i][j][k] + abs(next - k));
			}
		}
	}

	int min_val = 1e9;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			min_val = min(min_val, dp[l][i][j]);
	cout << min_val;
}
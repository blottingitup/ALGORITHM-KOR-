#include <iostream>
#include <algorithm>
using namespace std;

// i번째 행렬곱 A[i] * A[i + 1]에서 A[i]의 차원 ma[i - 1] * ma[i], A[i + 1]의 차원 ma[i] * ma[i + 1]
int ma[501], dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> ma[i] >> ma[i + 1];

	for (int i = 0; i < 501; i++)
		dp[i][i] = 0;
	for (int g = 1; g < n; g++) {
		for (int i = 1; i <= n - g; i++) {
			int j = i + g;
			dp[i][j] = INT32_MAX;
			// k번째 위치의 곱셈을 마지막으로 실행할 때 양쪽의 곱셈 횟수와 k번째 위치의 곱셈 횟수를 결합
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + ma[i - 1] * ma[k] * ma[j]);
		}
	}
	cout << dp[1][n];
}
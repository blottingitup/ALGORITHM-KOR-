#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, dp[31] = { 0, };
	cin >> n;
	dp[0] = 1, dp[2] = 3;
	if (n % 2) cout << 0;  // n은 홀수일 때 답은 0
	else {  // dp[n] = dp[n - 2] * 3 + dp[n - 4] * 2 + dp[n - 6] * 2 + ... + 2
		for (int i = 4; i <= n; i += 2) {
			dp[i] += dp[i - 2] * 3;  // 3*2 모양 추가
			for (int j = 4; i - j >= 0; j += 2)  // 점화식 마지막의 +2까지 포함
				dp[i] += dp[i - j] * 2;  // N >= 4일 때 고유 모양 추가
		}
		cout << dp[n];
	}
}
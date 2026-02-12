#include <iostream>
#include <algorithm>
using namespace std;

int dp[1101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n, cost[20], client[20];
	cin >> c >> n;
	for (int i = 0; i < n; i++)
		cin >> cost[i] >> client[i];

	fill(dp, dp + 1101, 1e9);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = client[i]; j < 1101; j++)
			dp[j] = min(dp[j], dp[j - client[i]] + cost[i]);
	}
	
	int real_min = 1e9;
	for (int i = c; i < 1101; i++)  // 사람 수가 c 이상일 때 모든 경우의 수 탐색
		real_min = min(real_min, dp[i]);
	cout << real_min;
}
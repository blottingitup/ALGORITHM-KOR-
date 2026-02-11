#include <iostream>
#include <utility>
using namespace std;

typedef long long int ll;
ll M[400];
pair<ll, ll> dp[400][400];  // { 범위 내의 총 마력 소모량, 남는 카드 }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> M[i];
		dp[i][i] = { 0, M[i] };  // 카드가 1장이면 마법을 사용할 필요가 없다
		// 또한 카드가 2장이면 두 카드의 마력량을 합하면 된다
		if (i) dp[i - 1][i] = { M[i - 1] + M[i], (M[i - 1] < M[i] ? M[i] : M[i - 1])};
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j < n - i; j++) {  // dp[j][j + i] 계산
			dp[j][j + i] = { (ll)1e18, 0 };  // 대표 카드의 초기값은 상관없음
			for (int k = j; k < j + i; k++) {  // dp[j][j + i] = dp[j][k] + dp[k + 1][j + i]
				ll sum_now = dp[j][k].first + dp[k + 1][j + i].first + dp[j][k].second + dp[k + 1][j + i].second;
				if (sum_now < dp[j][j + i].first) {
					dp[j][j + i].first = sum_now;
					dp[j][j + i].second = (dp[j][k].second < dp[k + 1][j + i].second ? dp[k + 1][j + i].second : dp[j][k].second);
				}
			}
		}
	}
	cout << dp[0][n - 1].first;
}
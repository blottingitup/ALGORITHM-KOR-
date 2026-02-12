#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001], ch[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fill(dp, dp + n + 1, 1000001);
	dp[0] = 0, dp[1] = 0;  // 초깃값 지정
	for (int i = 2; i <= n; i++) {
		// ch[i]에는 무엇으로 나누었는지 저장
		dp[i] = min(dp[i], dp[i - 1] + 1);  // 가장 기본적인 연산: -1
		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {  // 나누기 2 가능
			dp[i] = dp[i / 2] + 1;
			ch[i] = 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {  // 나누기 3 가능
			dp[i] = dp[i / 3] + 1;
			ch[i] = 3;
		}
	}
	
	int now = n;
	cout << dp[n] << "\n";
	while (now != 1) {
		cout << now << " ";
		if (ch[now] == 3) now /= 3;
		else if (ch[now] == 2) now /= 2;
		else now--;
	}
	cout << 1;
}
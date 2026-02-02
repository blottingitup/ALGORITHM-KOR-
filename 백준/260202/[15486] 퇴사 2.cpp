#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> job[1500002];
vector<int> dp(1500002);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		if (i + t > n + 1) continue;
		job[i + t].push_back({ t, p });  // i + t은 완료일
	}

	for (int i = 1; i <= n + 1; i++) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < job[i].size(); j++) {
			dp[i] = max(dp[i], dp[i - job[i][j].first] + job[i][j].second);
		}
	}
	cout << dp[n + 1];
}
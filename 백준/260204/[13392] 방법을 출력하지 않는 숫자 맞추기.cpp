#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

// dp[i][j]는 i번째 나사를 건드리지 않은 상태에서 왼쪽으로 j번 돌아갔을 때 최소 회전수의 합
int n, num[10001], target[10001], dp[10001][10];

int rev(int i, int j) {
	if (i > n) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int num_now = (num[i] + j + 10) % 10;  // i번째 나사를 직접 안돌린 상태에서 왼쪽으로 j번 돌아갔을 때 나오는 숫자
	int right = (num_now - target[i] + 10) % 10;  // i번째 나사를 오른쪽으로 돌려야 하는 횟수
	// (i + 1)번째 나사의 입장에서 보면, i번째 나사를 왼쪽으로 돌리는 옵션을 고려해야 함
	// 만약 i번째 나사를 왼쪽으로 돌리는 게 이득이면, 왼쪽으로 추가로 돌리는 횟수까지 고려
	return dp[i][j] = min(rev(i + 1, j) + right, rev(i + 1, (j + (10 - right) % 10) % 10) + (10 - right) % 10);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1, s2;
	cin >> n >> s1 >> s2;
	for (int i = 1; i <= n; i++) {
		num[i] = s1[i - 1] - '0';
		target[i] = s2[i - 1] - '0';
	}
	memset(dp, -1, sizeof(dp));
	cout << rev(1, 0);
}
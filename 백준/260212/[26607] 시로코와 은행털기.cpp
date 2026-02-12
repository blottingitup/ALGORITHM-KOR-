#include <iostream>
#include <algorithm>
using namespace std;

bool dp[81][16001];  // dp[i][j]: i명의 힘의 합이 j, 힘의 합은 최대 80 * 200

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, x, temp, power[81];
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++)
		cin >> power[i] >> temp;

	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {  // i번째 학생을 추가
		// 기존 j명의 상태는 오름차순으로 할 경우에 중복이 발생
		for (int j = k - 1; j >= 0; j--) {  // 기존에 j명이 있던 상태에서
			for (int l = 0; l <= k * x; l++) {  // 힘의 합이 l인 상태가 가능하다면
				if (dp[j][l]) dp[j + 1][l + power[i]] = true;  // i번째 학생을 추가해도 가능함
			}
		}
	}

	int max_sum = 0;
	for (int i = 0; i <= k * x; i++) {
		if (dp[k][i]) max_sum = max(max_sum, i * (k * x - i));
	}
	cout << max_sum;
}
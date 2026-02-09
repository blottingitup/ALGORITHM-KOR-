#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define INF 987654321
int n, map[16][16], dp[16][(1 << 16) - 1];
// dp[i][j]는 비용의 최솟값, 현재 i번째 도시, j는 도시 방문 상태의 비트마스크

int dfs(int from, int state) {
	if (state == (1 << n) - 1) {  // 모든 도시를 순회했을 때 state는 11...11
		if (!map[from][0]) return INF;  // 다시 최초의 도시로 돌아올 수 없을 때
		else return map[from][0];
	}
	
	if (dp[from][state] != -1) return dp[from][state];  // 이미 방문했으므로 계산 불필요
	dp[from][state] = INF;
	for (int i = 0; i < n; i++) {
		// i번째 도시를 방문하지 않았고 from -> i가 이동 가능할 경우
		if (((1 << i) & state) != (1 << i) && map[from][i])
			dp[from][state] = min(dp[from][state], map[from][i] + dfs(i, (1 << i) | state));
	}
	return dp[from][state];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	
	memset(dp, -1, sizeof(dp));  // 계산여부 확인하기 위해 -1로 초기화
	cout << dfs(0, 1);
}
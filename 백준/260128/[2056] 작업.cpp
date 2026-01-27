#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sc[10001][2], dp[10000];
vector<int> prec[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sc[i][0] >> sc[i][1];  // sc[i][0]은 해당 작업에 걸리는 시간, sc[i][1]은 선행 작업 개수
		for (int j = 0; j < sc[i][1]; j++) {
			int c;
			cin >> c;
			prec[i].push_back(c);
		}
	}

	dp[1] = sc[1][0];  // dp[1]은 고정
	for (int i = 2; i <= n; i++) {
		int max_time = 0;
		// 선행 작업이 전부 완료되어야 하므로 선행 작업이 마무리되는 시간의 최댓값부터 시작 가능
		// 선행 작업이 없으면 시간 0부터 시작 가능
		if(sc[i][1])
			for (int j = 0; j < sc[i][1]; j++)
				max_time = max(max_time, dp[prec[i][j]]);
		dp[i] = max_time + sc[i][0];  // i번째 작업이 끝나는 시간
	}

	// 모든 작업이 끝나야 하므로 dp[i] 중 최댓값 탐색
	int end = 0;
	for (int i = 1; i <= n; i++)
		end = max(end, dp[i]);
	cout << end;
}
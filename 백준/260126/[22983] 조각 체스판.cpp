#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

char chess[3000][3000];
ll ch[3000][3000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chess[i][j];
			ch[i][j] = 1LL;
		}
	}

	ll sum = n * m;  // 격자 한 칸짜리
	// 오른쪽 아래 칸을 기준으로, 왼쪽 위 대각선/가로/세로 조건 확인
	// 만약 모든 조건을 만족하면 체스판이 이 칸까지 확장 가능
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (chess[i][j] == chess[i - 1][j - 1] && chess[i][j] != chess[i - 1][j] && chess[i][j] != chess[i][j - 1]) {
				// 왼쪽 위 대각선/위/왼쪽에서 각각 몇 개의 가능성이 있는지 확인하고 최솟값 기록
				// 최솟값인 이유는 (i, j)에서는 3개 위치에서 모두 만족하는 경우의 수만을 가지기 때문
				ll ex = min({ch[i - 1][j - 1], ch[i - 1][j], ch[i][j - 1]});
				sum += ex;
				ch[i][j] = ex + 1;  // 체스판 만족했으므로 1 더해서 기록
			}
		}
	}
	cout << sum;
}
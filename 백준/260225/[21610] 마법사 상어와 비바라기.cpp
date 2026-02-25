#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int A[50][50];
bool cloud[50][50];
pair<int, int> dir[8] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
queue<pair<int, int>> q;  // 구름의 좌표

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= n - 2 && j < 2) q.push({ i, j });
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int d, s;
		cin >> d >> s;

		// 1, 2단계: 구름 이동, 바구니에 담긴 물의 양 1 증가
		int qs = q.size();
		for (int j = 0; j < qs; j++) {
			int a = q.front().first, b = q.front().second;
			q.pop();

			int aa = (a + 25 * n + dir[d - 1].first * s) % n, bb = (b + 25 * n + dir[d - 1].second * s) % n;
			q.push({ aa , bb });
			A[aa][bb]++;
		}

		// 2, 3단계
		vector<int> Aq;
		qs = q.size();
		for (int j = 0; j < qs; j++) {
			int a = q.front().first, b = q.front().second;
			cloud[a][b] = 1;  // 3단계: 기존 구름 소멸, 5단계를 위해 위치 기록

			int filled = 0;  // 대각선 4방향 중에서 물이 차있는 바구니 개수
			for (int k = 1; k < 8; k += 2) {
				int aa = a + dir[k].first, bb = b + dir[k].second;
				if (aa >= 0 && aa < n && bb >= 0 && bb < n && A[aa][bb])
					filled++;
			}
			Aq.push_back(filled);
			q.pop();
			q.push({ a, b });
		}

		// 4단계: 이전에 계산해둔 대각선 방향 물이 있는 바구니 개수에 따라 물복사버그
		for (int j = 0; j < qs; j++) {
			int a = q.front().first, b = q.front().second;
			A[a][b] += Aq[j];
			q.pop();
			q.push({ a, b });
		}

		// 5단계: 이전에 구름이 없었고 물의 양이 2 이상인 칸에서 물이 2 증발 후 구름 생성
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (!cloud[j][k] && A[j][k] >= 2) {
					A[j][k] -= 2;
					q.push({ j, k });
				}
			}
		}
		// 후처리: 3단계에서 소멸된 구름을 queue, cloud에서 제거
		for (int j = 0; j < qs; j++) {
			int a = q.front().first, b = q.front().second;
			cloud[a][b] = 0;
			q.pop();
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += A[i][j];
	cout << sum;
}
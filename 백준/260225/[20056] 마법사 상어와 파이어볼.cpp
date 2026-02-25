#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

queue<tuple<int, int, int>> F[50][50];
queue<tuple<int, int, int, int, int>> q;
pair<int, int> dir[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, kk;
	cin >> n >> m >> kk;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		q.push({ r, c, m, s, d });
	}

	for (int i = 0; i < kk; i++) {
		// 1단계: 파이어볼 이동
		int qs = q.size();
		for (int j = 0; j < qs; j++) {
			auto [r, c, m, s, d] = q.front();
			int rr = (r + 1000 * n + dir[d].first * s) % n, cc = (c + 1000 * n + dir[d].second * s) % n;
			F[rr][cc].push({ m, s, d });
			q.pop();
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				int fs = F[j][k].size();
				if (fs == 1) {  // 칸에 파이어볼이 1개면 건드릴 필요 없음
					auto [m, s, d] = F[j][k].front();
					q.push({ j, k, m, s, d });
					F[j][k].pop();
				}
				else if (fs > 1) {
					// 질량의 합, 속력의 합, 홀짝 방향의 개수 기록
					int m_sum = 0, s_sum = 0, d_odd = 0, d_even = 0;
					for (int l = 0; l < fs; l++) {
						auto [m, s, d] = F[j][k].front();
						m_sum += m;
						s_sum += s;
						if (d % 2) d_odd++;
						else d_even++;
						F[j][k].pop();
					}

					int m_new = m_sum / 5, s_new = s_sum / fs;  // 분열된 파이어볼의 질량과 속력
					if (m_new) {  // 분열된 파이어볼의 질량이 0이면 소멸
						int dir_odd = 0;  // 방향이 전부 홀수나 짝수면 나눠지는 방향은 0, 2, 4, 6
						if (d_odd && d_even) dir_odd++;  // 아니라면 1, 3, 5, 7
						for (int l = dir_odd; l < 8; l += 2)
							q.push({ j, k, m_new, s_new, l });
					}
				}
			}
		}
	}

	int sum = 0, qs = q.size();
	for (int i = 0; i < qs; i++) {
		auto [r, c, m, s, d] = q.front();
		sum += m;
		q.pop();
	}
	cout << sum;
}
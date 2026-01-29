#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, split = 0, sum = 0, pop[11];
	vector<int> adj[11];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pop[i];
		sum += pop[i];
	}
	for (int i = 1; i <= n; i++) {
		int ad;
		cin >> ad;
		for (int j = 0; j < ad; j++) {
			int adj_n;
			cin >> adj_n;
			adj[i].push_back(adj_n);
		}
	}

	bool ch1[11] = { 0, };
	for (int i = 1; i <= n; i++) {
		if (ch1[i]) continue;
		ch1[i] = true;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto a : adj[now]) {
				if (!ch1[a]) {
					q.push(a);
					ch1[a] = true;
				}
			}
		}
		split++;
	}

	if (split > 2) cout << -1;  // 인접 안한 지역이 3개 이상이면 2개의 선거구가 성립 안함
	else if (split == 2) {  // 인접 안한 지역이 2개면 그대로 선거구가 되므로 인구수 차 계산
		bool ch[11] = { 0, };
		int sum1 = pop[1];
		ch[1] = true;  // 아무 구역부터 시작해도 됨
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto a : adj[now]) {
				if (!ch[a]) {
					q.push(a);
					ch[a] = true;
					sum1 += pop[a];
				}
			}
		}
		int sum2 = sum - sum1;
		cout << (sum1 < sum2 ? sum2 - sum1 : sum1 - sum2);
	}
	else {  // 모든 지역이 인접해 있으면 2개의 선거구로 쪼개야 함
		int min_pop_diff = 1000;
		for (int i = 1; i <= n / 2; i++) {
			int mask[10] = { 0, };
			for (int j = n - i; j < n; j++)
				mask[j] = 1;
			do {
				vector<int> g1, g2;
				queue<int> q1, q2;
				int sum1 = 0, sum2 = 0;
				for (int j = 0; j < n; j++) {  // 선거구 나누기
					if (mask[j]) {
						g1.push_back(j + 1);
						sum1 += pop[j + 1];
					}
					else {
						g2.push_back(j + 1);
						sum2 += pop[j + 1];
					}
				}
				bool ch[11] = { 0, };
				int sum_diff = (sum1 < sum2 ? sum2 - sum1 : sum1 - sum2);

				// 첫 번째 선거구 BFS
				ch[g1[0]] = true;
				q1.push(g1[0]);
				while (!q1.empty()) {
					int now = q1.front();
					q1.pop();
					for (auto a : adj[now]) {
						if (!ch[a] && find(g1.begin(), g1.end(), a) != g1.end()) {
							ch[a] = true;
							q1.push(a);
						}
					}
				}
				// 두 번째 선거구 BFS
				ch[g2[0]] = true;
				q2.push(g2[0]);
				while (!q2.empty()) {
					int now = q2.front();
					q2.pop();
					for (auto a : adj[now]) {
						if (!ch[a] && find(g2.begin(), g2.end(), a) != g2.end()) {
							ch[a] = true;
							q2.push(a);
						}
					}
				}

				// 만약 두 선거구 전부 BFS를 돌았는데 방문하지 못한 구역이 있으면 잘못 짜여진 선거구
				bool good = true;
				for (int j = 1; j <= n; j++) {
					if (!ch[j]) {
						good = false;
						break;
					}
				}
				if (good) min_pop_diff = min(min_pop_diff, sum_diff);
			} while (next_permutation(mask, mask + n));
		}
		cout << min_pop_diff;
	}
}
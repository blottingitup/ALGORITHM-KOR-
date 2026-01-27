#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll n, m, t, s, g, h, a, b, d, dist[2001], path_before[2001];
		vector<ll> cand;
		vector<pair<ll, ll>> node[2001];
		cin >> n >> m >> t >> s >> g >> h;
		for (int j = 0; j < m; j++) {
			cin >> a >> b >> d;
			// 홀짝성을 이용해서 g-h 간선을 지났는지 확인
			d *= 2;  // g-h 간선 지외 모든 간선은 짝수 비용을 가짐
			if (a == g && b == h || a == h && b == g)  // 비용을 1 감소시켜 g-h 간선에 우선순위 부여
				d--;
			// 양방향
			node[a].push_back({ b, d });
			node[b].push_back({ a, d });
		}
		for (int j = 0; j < t; j++) {
			int v;
			cin >> v;
			cand.push_back(v);
		}
		sort(cand.begin(), cand.end());

		// 다익스트라
		fill(dist, dist + n + 1, (ll)1e18);
		fill(path_before, path_before + n + 1, 0);
		dist[s] = 0;
		priority_queue<pair<ll, ll>> pq;
		pq.push({ 0, s });
		while (!pq.empty()) {
			ll dist_now = -pq.top().first;
			ll node_now = pq.top().second;
			pq.pop();
			if (dist[node_now] < dist_now) continue;

			for (int j = 0; j < node[node_now].size(); j++) {
				auto [node_new, dist_new] = node[node_now][j];
				if (dist[node_new] > dist_now + dist_new) {
					dist[node_new] = dist_now + dist_new;
					pq.push({ -dist[node_new], node_new });
				}
			}
		}

		// 목적지 후보까지 최적 경로가 간선 g-h를 지나는지 확인
		// 기존 cost를 g-h 제외 전부 짝수로 설정하여 dist의 값이 홀수면 g-h를 지나서 목적지를 도달한 것
		for (int j = 0; j < cand.size(); j++)  // 목적지에 도달하지 못하거나 목적지에 도달할 때 g-h를 지나지 않음
			if (dist[cand[j]] == (ll)1e18 || !(dist[cand[j]] % 2)) cand[j] = 0;
		
		for (int j = 0; j < cand.size(); j++)
			if(cand[j]) cout << cand[j] << " ";
		cout << "\n";
	}
}
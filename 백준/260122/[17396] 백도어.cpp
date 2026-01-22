#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ll;
const ll INF = 1e15;

ll s[100000], dist[100000];
vector<pair<ll, ll>> node[100000];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++) {
		ll a, b, t;
		cin >> a >> b >> t;
		if ((s[a] == 1 && a != n - 1) || (s[b] == 1 && b != n - 1))  // 시야로 진입 불가 지역은 넘기기
			continue;
		node[a].push_back({ b, t });
		node[b].push_back({ a, t });
	}

	fill(dist + 1, dist + n, INF);  // 초기화
	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		ll cost_now = -pq.top().first;
		ll node_now = pq.top().second;
		pq.pop();

		if (dist[node_now] < cost_now) continue;
		for (ll i = 0; i < node[node_now].size(); i++) {
			ll node_next = node[node_now][i].first;
			ll cost_next = node[node_now][i].second;
			if (cost_next + cost_now < dist[node_next]) {
				dist[node_next] = cost_next + cost_now;
				pq.push({ -dist[node_next], node_next });
			}
		}
	}
	if (dist[n - 1] >= INF) cout << -1;
	else cout << dist[n - 1];
}
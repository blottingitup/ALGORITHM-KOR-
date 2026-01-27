#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;
ll dist[501];
vector<tuple<ll, ll, ll>> node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		node.push_back({ a, b, c });
	}

	// 음수 비용 간선 존재하므로 다익스트라 대신 벨만-포드 사용
	fill(dist, dist + n + 1, (ll)1e18);
	dist[1] = 0;
	for (ll i = 0; i < n - 1; i++) {
		for (ll j = 0; j < m; j++) {
			auto [a, b, c] = node[j];
			if (dist[a] == (ll)1e18) continue;  // 방문하지 않은 간선은 건너뛰기
			dist[b] = min(dist[b], dist[a] + c);  // 방문한적 있는 간선은 갱신
		}
	}

	// 음수 사이클 판별
	bool is_minus = false;
	for (ll i = 0; i < m; i++) {
		auto [a, b, c] = node[i];
		if (dist[a] == (ll)1e18) continue;
		if (dist[b] > dist[a] + c) {
			is_minus = true;
			break;
		}
	}

	if (is_minus) cout << -1;
	else {
		for (ll i = 2; i <= n; i++) {
			if (dist[i] == (ll)1e18) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}
}
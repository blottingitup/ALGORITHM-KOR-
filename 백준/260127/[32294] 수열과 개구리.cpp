#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef long long int ll;
ll a[200001], b[200001], dist[200001];
vector<pair<ll, ll>> node[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	// 각각의 노드를 출발점으로 해서 계산하면 시간 초과
	// 수열 밖의 임의의 노드(0)를 가정하고 다익스트라 계산을 위한 노드 연결
	// 각각 노드 x - a_x, x + a_x에서 노드 x까지 비용 b_x만큼 소모
	// 역방향 이동 가정: 수열 밖에서 수열 안의 노드 x까지 최단 비용 구하기
	for (ll i = 1; i <= n; i++) {
		if (i - a[i] < 1 || i + a[i] > n) node[0].push_back({ i, b[i] });  // 수열 밖
		if (i - a[i] >= 1 && i - a[i] <= n) node[i - a[i]].push_back({ i, b[i] });  // 수열 안: x - a_x
		if (i + a[i] >= 1 && i + a[i] <= n) node[i + a[i]].push_back({ i, b[i] });  // 수열 밖: x + a_x
	}

	fill(dist, dist + n + 1, (ll)1e18);
	dist[0] = 0;
	priority_queue<pair<ll, ll>> pq;
	pq.push({ 0, 0 });
	while (!pq.empty()) {
		ll dist_now = -pq.top().first;
		ll node_now = pq.top().second;
		pq.pop();
		if (dist[node_now] < dist_now) continue;

		for (int i = 0; i < node[node_now].size(); i++) {
			ll node_next = node[node_now][i].first;
			ll cost = node[node_now][i].second;
			if (dist[node_next] > dist[node_now] + cost) {
				dist[node_next] = dist[node_now] + cost;
				pq.push({ -dist[node_next], node_next });
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";
}
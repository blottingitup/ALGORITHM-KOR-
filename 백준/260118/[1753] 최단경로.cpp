#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> al(20001);
int dist[20001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		al[u].push_back({ v, w });
	}
	fill(dist, dist + v + 1, INT32_MAX);  // 전체 거리를 초기화
	dist[k] = 0;  // 시작점 거리는 0

	priority_queue<pair<int, int>> pq;  // priority queue로 거리 짧은 순으로 계산
	pq.push({ 0, k });
	while (!pq.empty()) {
		auto [dist_now, node_now] = pq.top();
		dist_now = -dist_now;
		pq.pop();

		if (dist[node_now] < dist_now) continue;  // 현재 거리가 더 짧은 경우 계산 불필요
		for (int i = 0; i < al[node_now].size(); i++) {  // 현재 노드에서 연결된 노드 비교
			int cost = dist_now + al[node_now][i].second;
			if (cost < dist[al[node_now][i].first]) {  // 비용 갱신
				dist[al[node_now][i].first] = cost;
				pq.push({ -cost, al[node_now][i].first });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT32_MAX) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
}
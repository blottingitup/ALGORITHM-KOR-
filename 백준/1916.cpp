#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> bus(n + 1);
	for (int i = 0; i < m; i++) {  // 인접 리스트에 저장
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		bus[a1].push_back({ a2, a3 });
	}

	int st, fin;
	vector<int> dist(n + 1, 100000001);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;  // 최소 힙
	cin >> st >> fin;
	dist[st] = 0;  // 시작점 초기화
	pq.push({ 0, st });  // 최소 힙으로 다익스트라를 효율적으로
	while (!pq.empty()) {
		int cur_node = pq.top().second;  // 현재 탐색 노드
		int cur_dist = pq.top().first;  // 가장 거리가 작은 노드를 자동으로
		pq.pop();
		if (cur_node == fin) break;  // 목적지까지의 거리가 나왔으므로 탐색 중단
		if (dist[cur_node] < cur_dist) continue;  // 이미 최소 거리가 나왔는데 탐색할 이유 없음

		for (int i = 0; i < bus[cur_node].size(); i++) {  // 모든 경로를 탐색
			auto [x, y] = bus[cur_node][i];
			int next_node = x;  // 인접 노드
			int next_dist = cur_dist + y;  // 인접 노드까지의 거리

			if (next_dist < dist[next_node]) {  // 최단 거리 찾아서 최소 힙에 추가
				dist[next_node] = next_dist;
				pq.push({ next_dist, next_node });
			}
		}
	}
	cout << dist[fin];
}
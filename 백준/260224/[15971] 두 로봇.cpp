#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> cave[100001];
bool visited[100001];
int res;

void dfs(int cur, int end, int max_len, int sum) {  // 각 경로마다 최대 path 길이와 전체 이동 거리를 저장
	if (cur == end) {
		res = sum - max_len;  // 전체 길이에서 가장 긴 path 길이를 빼면 최소 이동 거리
		return;
	}

	visited[cur] = true;
	for (pair<int, int> p : cave[cur]) {
		if (!visited[p.first]) dfs(p.first, end, max(max_len, p.second), sum + p.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		cave[x].push_back({ y, z });
		cave[y].push_back({ x, z });
	}

	dfs(a, b, 0, 0);
	cout << res;
}
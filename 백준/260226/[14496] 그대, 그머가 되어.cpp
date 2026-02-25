#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> A[1001];
bool visited[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, n, m;
	queue<int> q;
	cin >> a >> b >> n >> m;
	for (int i = 0; i < m; i++) {  // 양방향 그래프
		int ta, tb;
		cin >> ta >> tb;
		A[ta].push_back(tb);
		A[tb].push_back(ta);
	}

	if (a == b) {  // 예외 처리
		cout << 0;
		return 0;
	}

	q.push(a);
	int sum = 0, left = q.size();
	visited[a] = true;
	while (!q.empty()) {  // BFS
		left = q.size();

		while (left--) {
			int now = q.front();
			q.pop();
			if (now == b) {
				cout << sum;
				return 0;
			}

			for (int i = 0; i < A[now].size(); i++) {
				if (!visited[A[now][i]]) {
					visited[A[now][i]] = true;
					q.push(A[now][i]);
				}
			}
		}
		sum++;	
	}
	cout << -1;  // BFS를 수행했음에도 b에 도달하지 못했으므로 -1 출력
}
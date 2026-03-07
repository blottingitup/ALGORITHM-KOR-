#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> moo[5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		moo[a].push_back({ b, c });
		moo[b].push_back({ a, c });
	}

	for (int i = 0; i < q; i++) {
		int k, v, sum = 0;
		cin >> k >> v;

		// DFS
		bool visited[5001] = { 0, };
		visited[v] = true;
		vector<int> st;
		st.push_back(v);
		while (!st.empty()) {
			int now = st.back();
			st.pop_back();

			for (int j = 0; j < moo[now].size(); j++) {
				if (!visited[moo[now][j].first]) {
					visited[moo[now][j].first] = true;
					// USADO가 k 이상인 노드만 스택에 삽입
					// k 이상인 노드로만 목적지에 도달 못하면 추천되지 않음
					if (moo[now][j].second >= k) {
						st.push_back(moo[now][j].first);
						sum++;
					}
				}
			}
		}

		cout << sum << "\n";
	}
}
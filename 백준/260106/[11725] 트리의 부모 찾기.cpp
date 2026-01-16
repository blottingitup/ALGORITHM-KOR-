#include <iostream>
#include <vector>
using namespace std;

bool ch[100001];
int parent[100001];

void dfs(vector<vector<int>> &g, int n) {
	ch[n] = true;
	for (int i = 0; i < g[n].size(); i++) {
		if (ch[g[n][i]]) continue;
		parent[g[n][i]] = n;
		dfs(g, g[n][i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, node1, node2;
	vector<vector<int>> g;
	vector<int> temp;
	cin >> n;
	for (int i = 0; i <= n; i++)
		g.push_back(temp);
	for (int i = 1; i < n; i++) {
		cin >> node1 >> node2;
		g[node1].push_back(node2);
		g[node2].push_back(node1);
	}

	dfs(g, 1);
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}
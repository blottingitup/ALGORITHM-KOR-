#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> ad_list, child_list;
vector<int> temp_list, sub_size;

void make_tree(int cur_node, int parent) {
	for (auto node : ad_list[cur_node]) {  // 인접 리스트에서 연결된 노드 탐색
		if (node != parent) {  // 부모는 하나 혹은 없음
			child_list[cur_node].push_back(node);  // 자식 리스트에 추가
			make_tree(node, cur_node);  // 재귀를 통해 트리 아래쪽으로 내려감
		}
	}
}

void count_sub(int cur_node) {
	sub_size[cur_node] = 1;  // 기본적으로 본인도 포함
	for (auto node : child_list[cur_node]) {  // 자식 리스트를 순회
		// 재귀적으로 자식들을 전부 탐색한 후 반영
		count_sub(node);
		sub_size[cur_node] += sub_size[node];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, q, u, v;
	cin >> n >> r >> q;
	for (int i = 0; i <= n; i++) {
		ad_list.push_back(temp_list);
		child_list.push_back(temp_list);
		sub_size.push_back(0);
	}
	for (int i = 0; i < n - 1; i++) {  // 인접 리스트
		cin >> u >> v;
		ad_list[u].push_back(v);
		ad_list[v].push_back(u);
	}

	// 트리의 루트에서 초기화 하면 트리와 자식 노드의 개수를 저장
	make_tree(r, -1);
	count_sub(r);
	for (int i = 0; i < q; i++) {
		cin >> u;
		cout << sub_size[u] << "\n";
	}
}
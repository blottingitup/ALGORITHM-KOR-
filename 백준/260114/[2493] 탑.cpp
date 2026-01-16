#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<pair<int, int>> tower;
	vector<int> where;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		if (tower.empty()) {  // 스택이 비어있을 때
			tower.push_back({ i, h });
			where.push_back(0);
		}
		else if (tower.back().second > h) {  // 가장 오른쪽의 탑이 더 높을 때
			where.push_back(tower.back().first);
			tower.push_back({ i, h });
		}
		else {  // 가장 오른쪽의 탑이 더 낮을 때
			while (!tower.empty() && tower.back().second <= h)  // 더 높은 탑이 나올 때까지 pop
				tower.pop_back();
			if (tower.empty())
				where.push_back(0);
			else
				where.push_back(tower.back().first);
			tower.push_back({ i, h });
		}
	}
	for (auto x : where) cout << x << " ";
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, d[50][50];
	vector<pair<int, int>> house, chicken;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
			if (d[i][j] == 1) house.push_back({ i, j });
			else if (d[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	// M개의 치킨집을 조합을 이용해 구하고 집들의 좌표를 이용해 최솟값을 탐색
	int bef = chicken.size(), min_city = INT32_MAX, arr[13] = { 0, };
	for (int i = bef - m; i < bef; i++)
		arr[i] = 1;
	do {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {  // 모든 집에 대해
			int min_house = INT32_MAX;
			for (int j = 0; j < bef; j++) {  // 선택된 치킨집들까지의 최소 거리를 합해서 도시의 치킨 거리를 비교
				if (!arr[j]) continue;
				min_house = min(min_house, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
			}
			sum += min_house;
		}
		min_city = min(min_city, sum);
	} while (next_permutation(arr, arr + bef));

	cout << min_city;
}
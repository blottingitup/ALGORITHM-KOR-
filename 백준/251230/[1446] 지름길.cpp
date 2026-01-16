#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dist[10001];

bool compare(vector<int> &v1, vector<int> &v2) {
	if (v1[1] == v2[1]) {  // 도착 지점 동률
		if (v1[2] == v2[2])  // 지름길 길이 동률
			return v1[0] < v2[0];  // 시작 지점 순서
		else
			return v1[2] < v2[2];
	}
	return v1[1] < v2[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, d, cnt = 0;
	vector<vector<int>> shortcut;

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		vector<int> temp(3);
		cin >> temp[0] >> temp[1] >> temp[2];
		if (temp[1] > d) continue;  // 역주행 불가
		shortcut.push_back(temp);
	}
	sort(shortcut.begin(), shortcut.end(), compare);

	for (int i = 1; i <= d; i++) {
		dist[i] = dist[i - 1] + 1;  // 위치 i까지의 최대 거리
		while (cnt < shortcut.size() && shortcut[cnt][1] == i) {  // 지름길에서 도착 지점 i
			if (dist[shortcut[cnt][0]] + shortcut[cnt][2] < dist[i])  // 지름길 통과
				dist[i] = dist[shortcut[cnt][0]] + shortcut[cnt][2];
			cnt++;
		}
	}
	cout << dist[d];
}
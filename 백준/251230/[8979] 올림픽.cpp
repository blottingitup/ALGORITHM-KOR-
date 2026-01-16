#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int> &v1, vector<int> &v2) {
	if (v1[0] == v2[0]) {  // 금메달 동률
		if (v1[1] == v2[1])  // 은메달 동률
			return v1[2] > v2[2];
		else
			return v1[1] > v2[1];
	}
	return v1[0] > v2[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, num, cnt = 0;
	int gm, sm, bm;
	vector<vector<int>> medal;
	vector<int> temp(4);
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		medal.push_back(temp);

	for (int i = 0; i < n; i++) {
		cin >> medal[i][3] >> medal[i][0] >> medal[i][1] >> medal[i][2];
		if (medal[i][3] == k) {
			gm = medal[i][0];  // 국가 k의 금메달 개수
			sm = medal[i][1];  // 국가 k의 은메달 개수
			bm = medal[i][2];  // 국가 k의 동메달 개수
		}
	}

	sort(medal.begin(), medal.end(), compare);
	for (int i = 0; i < n; i++) {
		cnt++;
		if (medal[i][0] == gm && medal[i][1] == sm && medal[i][2] == bm) break;
	}
	cout << cnt;
}
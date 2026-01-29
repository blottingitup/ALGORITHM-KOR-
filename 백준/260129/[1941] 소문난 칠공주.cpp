#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[25] = { 0, };
	char classroom[5][5];
	vector<vector<int>> all;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> classroom[i][j];
	for (int i = 18; i < 25; i++)  // 조합 구하기 위해 마스킹
		arr[i] = 1;

	do {  // 조합을 구해서 먼저 학생 간 파벌 비율 비교
		int s_sum = 0, y_sum = 0;
		vector<int> temp;
		for (int i = 0; i < 25; i++) {
			if (arr[i] == 1) {
				if (classroom[i / 5][i % 5] == 'S') s_sum++;
				else y_sum++;
				temp.push_back(i);
			}
		}
		if (s_sum > y_sum)  // 파벌 비율 조건 만족
			all.push_back(temp);
	} while (next_permutation(arr, arr + 25));

	int sum = 0, xdir[4] = { -1, 0, 1, 0 }, ydir[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < all.size(); i++) {
		int found = 1;
		bool ch[5][5] = { 0, };
		queue<pair<int, int>> bfs;
		bfs.push({ all[i][0] / 5, all[i][0] % 5 });
		ch[all[i][0] / 5][all[i][0] % 5] = true;
		all[i].erase(remove(all[i].begin(), all[i].end(), all[i][0]), all[i].end());  // 이미 탐색한 공주는 목록에서 제거
		while (!bfs.empty()) {
			auto [x, y] = bfs.front();
			bfs.pop();

			if (found == 7) break;

			for (int j = 0; j < 4; j++) {  // BFS 실행
				int xx = x + xdir[j], yy = y + ydir[j];
				if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5 && !ch[xx][yy]) {
					ch[xx][yy] = true;  // 방문 표시는 무조건 해줌

					for (auto a : all[i]) {  // 공주 목록을 순회하며 인접한지 확인
						if (xx == a / 5 && yy == a % 5) {
							bfs.push({ xx, yy });
							all[i].erase(remove(all[i].begin(), all[i].end(), xx * 5 + yy), all[i].end());
							found++;  // 인접한 공주 몇 명 찾았는지 확인
						}
					}
				}
			}
		}

		if (found == 7) sum++;
	}
	cout << sum;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

char arr[12][6];
bool visited[12][6];
pair<int, int> dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int search(int x, int y) {
	char start = arr[x][y];
	vector<pair<int, int>> v;  // 현재 기준 색과 같은 색의 위치의 좌표 저장
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {  // BFS
		auto [a, b] = q.front();
		v.push_back({ a, b });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int aa = a + dir[i].first, bb = b + dir[i].second;
			if (aa >= 0 && aa < 12 && bb >= 0 && bb < 6 && !visited[aa][bb]) {
				if (arr[aa][bb] == start) {
					visited[aa][bb] = true;
					q.push({ aa, bb });
				}
			}
		}
	}

	if (v.size() >= 4) {  // 연쇄로 인해 .으로 변화
		for (int i = 0; i < v.size(); i++) {
			arr[v[i].first][v[i].second] = '.';
		}
		return 1;  // 연쇄로 인해 폭발이 일어나면 1 반환
	}
	return 0;  // 그렇지 않으면 0 반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];

	int sum = 0;
	while (1) {
		fill_n(visited[0], 12 * 6, false);
		int burst = 0;  // 이번 연쇄에서 일어난 폭발 횟수
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '.') continue;
				burst += search(i, j);
			}
		}

		if (!burst) break;  // 폭발이 0회 일어났으면 종료

		for (int i = 0; i < 6; i++) {
			vector<char> temp;  // 각 열마다 아래에서부터 남아있는 색을 저장
			for (int j = 11; j >= 0; j--)
				if (arr[j][i] != '.')
					temp.push_back(arr[j][i]);
			for (int j = 11; j > 11 - temp.size(); j--)  // 아래에서부터 채워넣고
				arr[j][i] = temp[11 - j];
			for (int j = 11 - temp.size(); j >= 0; j--)  // 남은 위쪽 공간은 빈칸으로 다시 채움
				arr[j][i] = '.';
		}

		sum++;
	}
	cout << sum;
}
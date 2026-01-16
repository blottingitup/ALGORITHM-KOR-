#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, t1, t2;
	vector<pair<int, int>> ladder, snake;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		ladder.push_back({ t1, t2 });
	}
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2;
		snake.push_back({ t1, t2 });
	}

	int sum = 0, ch1 = 1, ch2 = 0;
	bool visited[101] = { false, };
	deque<int> game;
	game.push_back(1);
	while (!game.empty()) {  // BFS, 갔던 칸에 다시 갈 수 있음
		int n = game.front();
		if (!ch1) {  // 이동 횟수
			sum++;  // 이번 회차에서 전부 탐색했으면 이동 횟수 증가
			ch1 = ch2;  // 이번 회차에서 탐색해야 하는 경우의 수 초기화
			ch2 = 0;
		}
		ch1--;  // 이번 회차에 남은 경우의 수
		if (n == 100) break;
		game.pop_front();
		for (int i = 1; i <= 6; i++) {  // 주사위는 1에서 6까지
			bool flag = true;
			if (n + i > 100) break;
			if (visited[n + i]) continue;
			ch2++;  // 다음 회차에 이동 가능한 경우의 수
			for (int j = 0; j < ladder.size(); j++) {  // 사다리
				if (ladder[j].first == n + i) {
					game.push_back(ladder[j].second);
					visited[ladder[j].second] = true;
					flag = false;
					break;
				}
			}
			for (int j = 0; j < snake.size(); j++) {  // 뱀
				if (snake[j].first == n + i) {
					game.push_back(snake[j].second);
					visited[snake[j].second] = true;
					flag = false;
					break;
				}
			}
			if (flag) {
				game.push_back(n + i);  // 단순 이동
				visited[n + i] = true;
			}
		}
	}
	cout << sum;
}
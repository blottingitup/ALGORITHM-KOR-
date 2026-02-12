#include <iostream>
#include <string>
using namespace std;

string scan[3];
int leftover;
bool found = false;

void move_s(string dir) {  // 이동방향에 따라 자동으로 cout, cin 실행
	for (int l = 0; l < dir.size(); l++) {
		cout << "? " << dir[l] << endl;
		for (int i = 0; i < 3; i++)
			cin >> scan[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool first = true;
	int left1 = 0, down = 0, n = -1;
	string dir = "";
	for (int i = 0; i < 3; i++)
		cin >> scan[i];
	
	while (1) {
		// 전체 9칸을 스캔
		for (int i = 0; i < 3; i++) {
			if (found) break;
			for (int j = 0; j < 3; j++) {
				if (i == 1 && i == j) continue;
				if (scan[i][j] == 'G') {
					if (j == 0) {
						if (i == 0) dir = "LU";
						else if (i == 1) dir = "L";
						else dir = "LD";
					}
					else if (j == 2) {
						if (i == 0) dir = "RU";
						else if (i == 1) dir = "R";
						else dir = "RD";
					}
					else {
						if (i == 0) dir = "U";
						else dir = "D";
					}
					move_s(dir);
					found = true;
					break;
				}
			}
		}

		if (found) break;
		if (leftover) {
			move_s("R");
			leftover--;
			continue;
		}
		if (scan[1][1] == 'R' && !first) {  // 위로만 이동해서 한바퀴 이동 완료 (최초)
			move_s("R");  // 오른쪽으로 3칸 이동해서 새로운 구역 탐색
			leftover = 2;
			left1++;
			n = down;
			down = 0;
			continue;
		}
		else if (down == n) {  // 새로운 구역도 한바퀴 이동 완료
			move_s("R");  // 오른쪽으로 3칸 이동해서 새로운 구역 탐색
			leftover = 2;
			left1++;
			down = 0;
			continue;
		}
		move_s("U");  // 기본적으로 위로 1칸 이동
		first = false;
		down++;
	}

	// 움직였던 것의 역순으로 이동
	for (int i = 0; i < left1 * 3 - leftover; i++)
		move_s("L");
	for (int i = 0; i < down; i++)
		move_s("D");

	if (dir.size()) {
		if (dir[0] == 'L') move_s("R");
		else if (dir[0] == 'R') move_s("L");
		else if (dir[0] == 'U') move_s("D");
		else move_s("U");

		if (dir.size() == 2) {
			if (dir[1] == 'U') move_s("D");
			else move_s("U");
		}
	}
	cout << "!" << endl;
}
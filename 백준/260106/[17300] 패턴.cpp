#include <iostream>
#include <cmath>
using namespace std;

int sq[3][3];
bool flag[3][3];

bool traverse(int* p, int now) {
	int startx = (p[now] - 1) / 3, starty = (p[now] - 1) % 3;  // 좌표 변환
	int jumpx = (p[now + 1] - 1) / 3, jumpy = (p[now + 1] - 1) % 3;  // 다음 좌표 변환
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == j && !i) continue;  // 8방향 모두 확인
			int xx = startx + i, yy = starty + j;
			if (xx < 0 || xx > 2 || yy < 0 || yy > 2) continue;
			if (sq[xx][yy] == p[now + 1]) return true;  // 다음 점이 직접 연결되어 있어야 함
		}
	}

	// 이전에 지나간 점을 가로지를 때
	if (abs(jumpx - startx) == 2 && abs(jumpy - starty) <= 1) {  // 세로
		if (abs(jumpy - starty) == 1) return true;  // 점을 거치지 않을 때
		else if (flag[1][jumpy]) return true;  // 점을 거칠 때
	}
	else if (abs(jumpy - starty) == 2 && abs(jumpx - startx) <= 1) {  // 가로
		if (abs(jumpx - startx) == 1) return true;    // 점을 거치지 않을 때
		else if (flag[jumpx][1]) return true;  // 점을 거칠 때
	}
	else if (abs(jumpx - startx) == 2 && abs(jumpy - starty) == 2)  // 대각선
		if (flag[1][1]) return true;

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, now = 0, p[9] = { 0, }, ch[10] = { 0, };
	bool allowed = true, cont = true;
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> p[i];
		ch[p[i]]++;
	}

	if (l < 3) allowed = false;  // 길이는 3 이상
	for (int i = 1; i < 10; i++)  // 중복 불가
		if (ch[i] > 1) allowed = false;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			sq[i][j] = i * 3 + j + 1;
	while (allowed && now < l - 1) {  // 3 X 3 패턴 위에서 주변 탐색, 연결 가능한지 확인
		flag[(p[now] - 1) / 3][(p[now] - 1) % 3] = true;
		cont = traverse(p, now);  // 연속 여부
		if (!cont) {
			allowed = false;
			break;
		}
		now++;
	}

	if (allowed) cout << "YES";
	else cout << "NO";
}
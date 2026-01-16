#include <iostream>
#include <cmath>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;
	// x좌표와 y좌표의 차이의 홀짝성 비교
	if (abs(xa - xb) % 2 != abs(ya - yb) % 2)  // 둘 중 하나만 홀수면 불가능
		cout << -1;
	else {  // 둘 다 홀수, 아니면 둘 다 짝수
		int x = (xa < xb ? xa : xb) + abs(xa - xb) / 2;
		int y = (ya < yb ? ya : yb) + abs(ya - yb) / 2;
		if (abs(xa - xb) % 2 == 1)  // 홀수이고 두 점을 연결했을 때 우상향하는 대각선일 때
			if ((xa < xb && ya < yb) || (xa > xb && ya > yb))
				y++;

		cout << x << " " << y;
	}
}
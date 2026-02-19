#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {  // CCW 함수
	ll temp = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (temp > 0) return 1;
	else if (temp < 0) return -1;
	else return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll x1, x2, x3, x4, y1, y2, y3, y4, v[4];
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	v[0] = ccw(x1, y1, x2, y2, x3, y3);
	v[1] = ccw(x1, y1, x2, y2, x4, y4);
	v[2] = ccw(x3, y3, x4, y4, x1, y1);
	v[3] = ccw(x3, y3, x4, y4, x2, y2);

	if (v[0] * v[1] == 0 && v[2] * v[3] == 0) {  // 선분끼리 겹치는 경우 (4점이 일직선 상에 위치)
		pair<ll, ll> p1 = { x1, y1 }, p2 = { x2, y2 };
		pair<ll, ll> p3 = { x3, y3 }, p4 = { x4, y4 };

		if (p1 > p2) swap(p1, p2);
		if (p3 > p4) swap(p3, p4);

		if (p1 <= p4 && p3 <= p2) cout << 1;
		else cout << 0;
	}
	// 한 선분에 대해 두 점의 CCW가 어긋나는 경우
	else if (v[0] * v[1] <= 0 && v[2] * v[3] <= 0) cout << 1;
	else cout << 0;
}

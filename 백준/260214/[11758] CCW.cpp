#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x1, x2, x3, y1, y2, y3, z;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	z = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (z > 0) cout << 1;
	else if (z == 0) cout << 0;
	else cout << -1;
}
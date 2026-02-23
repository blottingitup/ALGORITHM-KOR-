#include <iostream>
using namespace std;

int comb(int n, int r) {  // 조합
	if (n == r || !r) return 1;
	return comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	if (!k) cout << comb(n + m - 2, m - 1);  // (1, 1)에서 (n, m)까지의 경우의 수
	else {  // (1, 1)에서 k까지의 경우의 수 * k에서 (n, m)까지의 경우의 수
		int m2 = k % m;
		int n2 = !m2 ? k / m : k / m + 1;
		if (!m2) m2 = m;
		int n3 = n - n2 + 1, m3 = m - m2 + 1;
		cout << comb(n2 + m2 - 2, m2 - 1) * comb(n3 + m3 - 2, m3 - 1);
	}
}
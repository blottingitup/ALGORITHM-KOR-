#include <iostream>
using namespace std;

int l[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	l[0] = 1, l[1] = 3;
	for (int i = 2; i <= n; i++) {
		int temp = (2 * (l[i - 1] % 9901)) % 9901;
		l[i] = (temp % 9901 + l[i - 2] % 9901) % 9901;
	}
	cout << l[n];
}
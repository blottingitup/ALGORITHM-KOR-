#include <iostream>
#include <algorithm>
using namespace std;

int num[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(num, num + 10001, 1);
	for (int i = 2; i <= 10000; i++)
		num[i] += num[i - 2];
	for (int i = 3; i <= 10000; i++)
		num[i] += num[i - 3];

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << num[n] << "\n";
	}
}
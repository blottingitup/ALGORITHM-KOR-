#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num[100002] = { 0, };
	bool prime[100002];
	fill(prime, prime + 100001, 1);

	prime[1] = false;
	for (int i = 2; i <= 100001; i++) {  // 에라토스테네스의 체
		if (prime[i]) {
			for (int j = 2 * i; j <= 100001; j += i)
				prime[j] = false;
		}
	}

	for (int i = 1; i <= 100000; i++) {
		if (i < 10) {
			if (prime[i + 1]) num[i] = num[i - 1] + 1;
			else num[i] = num[i - 1];
		}
		else {
			if (!prime[i + 1]) {  // n + 1은 소수
				num[i] = num[i - 1];
				continue;
			}
			string s = to_string(i);
			int len = s.size();
			bool real = true;
			for (int j = 1; j < len; j++) {  // 소수 규칙
				int ch = stoi(s.substr(0, j)) * stoi(s.substr(j)) + 1;
				if (!prime[ch]) {
					real = false;
					break;
				}
			}
			if (real) num[i] = num[i - 1] + 1;
			else num[i] = num[i - 1];
		}
	}

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << num[n] << "\n";
	}
}
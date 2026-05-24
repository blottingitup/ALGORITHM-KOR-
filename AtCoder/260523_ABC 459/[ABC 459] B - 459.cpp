#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] <= 'c') cout << 2;
		else if (s[0] <= 'f') cout << 3;
		else if (s[0] <= 'i') cout << 4;
		else if (s[0] <= 'l') cout << 5;
		else if (s[0] <= 'o') cout << 6;
		else if (s[0] <= 's') cout << 7;
		else if (s[0] <= 'v') cout << 8;
		else if (s[0] <= 'z') cout << 9;
	}
}
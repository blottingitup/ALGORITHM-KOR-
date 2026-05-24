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

	string s = "HelloWorld";
	int x;
	cin >> x;
	for (int i = 0; i < 10; i++) {
		if (i == x - 1) continue;
		cout << s[i];
	}
}
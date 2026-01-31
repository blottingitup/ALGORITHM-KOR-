#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, i;
	cin >> n >> k;
	for (i = 0; ; i++) {
		k -= n++;
		if (k <= 0) break;
	}
	cout << i;
}
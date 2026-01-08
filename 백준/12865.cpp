#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bag[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, temp1, temp2;
	vector<int> stuff(1), value(1);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> temp2;
		stuff.push_back(temp1);
		value.push_back(temp2);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (stuff[i] > j) bag[i][j] = bag[i - 1][j];
			else bag[i][j] = max(bag[i - 1][j], value[i] + bag[i - 1][j - stuff[i]]);
		}
	}
	cout << bag[n][k];
}
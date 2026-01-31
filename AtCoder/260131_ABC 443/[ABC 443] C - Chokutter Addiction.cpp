#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int arr[300000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t, start = 0, sum = 0;
	cin >> n >> t;
	if (!n) cout << t;
	else {
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++) {
			if (arr[i] > t || start >= t) break;
			if (arr[i] > start) {
				sum += arr[i] - start;
				start = arr[i] + 100;
			}
		}
		if (start < t) sum += t - start;
		cout << sum;
	}
}
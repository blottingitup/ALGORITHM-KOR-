#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ch[100001];
vector<int> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	int end = 0, max_len = 1;
	for (int start = 0; start < n; start++) {
		while (end < n && ch[a[end]] + 1 <= k) ch[a[end++]]++;
		max_len = max(max_len, end - start);  // [start, end)
		if (end == n) break;
		ch[a[start]]--;
	}
	cout << max_len;
}
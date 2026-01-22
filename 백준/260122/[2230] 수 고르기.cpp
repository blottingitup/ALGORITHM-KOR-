#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int start = 0, end = 1, min_diff = INT32_MAX;
	while (start < n - 1) {
		int diff = arr[end] - arr[start];
		if (diff >= m) {
			min_diff = min(min_diff, diff);  // 차이의 최솟값 찾기
			start++;  // 더 m에 가까운 최솟값 찾기 위해 start 증가
		}
		else {
			if (end < n - 1) end++;  // 그게 아니면 최대한 end 증가
			else start++;  // 아니면 start 증가
		}
	}
	if (n == 1) cout << 0;
	else cout << min_diff;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> lis;

int bin_search(int start, int end, int element) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (lis[mid] < element) start = mid + 1;
		else end = mid;
	}
	return end;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		// 현재 숫자가 증가하는 부분 수열의 최댓값보다 크면 그대로 수열 끝에 붙이기
		if (!i || a[i] > lis.back()) lis.push_back(a[i]);
		else {  // 아니면 증가하는 부분 수열에서 차지할 수 있는 위치 확인
			int pos = bin_search(0, lis.size() - 1, a[i]);  // 이분 탐색 이용
			lis[pos] = a[i];
		}
	}
	cout << lis.size();
}
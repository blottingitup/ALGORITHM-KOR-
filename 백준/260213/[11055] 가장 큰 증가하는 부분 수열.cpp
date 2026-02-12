#include <iostream>
#include <algorithm>
using namespace std;

int A[1000], sum[1000];  // sum은 증가하는 부분 수열의 합의 최댓값을 저장

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum_max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int i = 0; i < n; i++) {
		sum[i] = A[i];  // 본인으로 초기화
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) sum[i] = max(sum[i], sum[j] + A[i]);
		}
		sum_max = max(sum_max, sum[i]);
	}
	cout << sum_max;
}
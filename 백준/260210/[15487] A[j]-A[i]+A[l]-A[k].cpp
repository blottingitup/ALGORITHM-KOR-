#include <iostream>
#include <algorithm>
using namespace std;

int A[1000000], leftA[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, max_sum = -1e9;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];

	// [0, j] 범위에서 A[j] - A[i]의 최댓값
	int minA = A[0];
	leftA[0] = -1e9;
	for (int j = 1; j < n - 2; j++) {  // A[j] 뒤에 최소 숫자 2개 더 존재
		leftA[j] = max(leftA[j - 1], A[j] - minA);  // minA는 [0, j) 범위에서 최솟값
		minA = min(minA, A[j]);
	}

	// [k, n) 범위에서 A[l] - A[k]의 최댓값 구하고 최종 결과 합산
	int maxA = A[n - 1], rightA = -1e9;
	for (int k = n - 2; k > 1; k--) {  // A[k] 앞에 최소 숫자 2개 더 존재
		rightA = max(rightA, maxA - A[k]);  // 마찬가지로 maxA는 (k, n) 범위에서 최솟값
		max_sum = max(max_sum, leftA[k - 1] + rightA);  // (A[j] - A[i])의 최댓값 + (A[l] - A[k])의 최댓값
		maxA = max(maxA, A[k]);
	}
	cout << max_sum;
}
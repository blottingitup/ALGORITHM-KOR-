#include <iostream>
#include <deque>
using namespace std;

int A[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, x;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)  // 수열의 기본 상태는 오름차순 정렬
		A[i] = i;
	x = n - k;
	if (!x) cout << "Impossible";  // k == n면 불가능
	else if (x == 1) {  // k == n - 1이면 오름차순 정렬 그대로
		for (int i = 1; i <= n; i++)
			cout << A[i] << " ";
	}
	else {  // k == n - x: 일단 1개의 gcd(i, A[i]) = 1인 항이 1개 있음
		if (x % 2) {  // 연속된 x / 2개의 쌍을 서로 교환하여 추가 gcd(i, A[i]) = 1인 항을 짝수개 추가
			int cnt = 0;
			for (int i = 2; cnt < x / 2; i += 2) {
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				cnt++;
			}
		}
		else {  // 연속된 x / 2 - 1개의 쌍을 서로 교환
			int cnt = 1;
			for (int i = 2; cnt < x / 2; i += 2) {
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				cnt++;
			}
			// 추가로 1과 맨 끝의 수를 교환하여 gcd(i, A[i]) = 1인 항을 1개 더 만들어서 짝수개가 됨
			A[1] = n;
			A[n] = 1;
		}
		for (int i = 1; i <= n; i++)
			cout << A[i] << " ";
	}
}
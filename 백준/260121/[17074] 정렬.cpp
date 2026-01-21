#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, change = 0, pos, arr[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 오름차순 정렬되어 있지 않은 부분의 개수
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			change++;
			pos = i;
		}
	}
	if (change >= 2) cout << 0;  // 2개면 최종적으로 오름차순 정렬이 불가능
	else if (!change) cout << n;  // 없으면 어느 것을 빼도 상관없으므로 N
	else {
		int sum = 0;
		if (n == 2) sum = 2;  // 길이가 2일 때
		else if (pos == n - 2) {  // pos + 2가 불가능해서 따로 빼둔 경우
			if (arr[pos - 1] <= arr[pos + 1]) sum = 2;  // arr[pos] 빼기
			else sum = 1;  // arr[n - 1]은 무조건 빠질 수 있음
		}
		else if (pos == 0) {
			if (arr[pos] <= arr[2]) sum = 2;  // arr[1] 빼기
			else sum = 1;  // arr[0]은 무조건 빠질 수 있음
		}
		else {
			if (arr[pos] <= arr[pos + 2]) sum++;  // arr[pos + 1] 빼기
			if (arr[pos - 1] <= arr[pos + 1]) sum++;  // arr[pos] 빼기
		}
		cout << sum;
	}
}
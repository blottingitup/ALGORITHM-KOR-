#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// num[i][0]은 길이 i인 이친수 중 끝자리가 0인 것의 개수
	// num[i][1]은 길이 i인 이친수 중 끝자리가 1인 것의 개수
	long long int num[91][2];
	num[1][0] = 0, num[1][1] = 1LL;
	num[2][0] = 1LL, num[2][1] = 0;

	for (int i = 3; i <= n; i++) {
		num[i][0] = num[i - 1][0] + num[i - 1][1];
		num[i][1] = num[i - 1][0];
	}
	cout << num[n][0] + num[n][1];
}
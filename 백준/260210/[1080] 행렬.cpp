#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int A[50][50], B[50][50], d[50][50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, sum = 0;
	string temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++)
			A[i][j] = temp[j] - '0';
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			B[i][j] = temp[j] - '0';
			// 행렬 전체 크기가 3*3보다 작으면 연산 불가
			if ((n < 3 || m < 3) && A[i][j] != B[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	// 행렬 변환 연산은 A[i][j]가 왼쪽 위가 되로록 3*3 범위를 변화시킴
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if ((A[i][j] + d[i][j]) % 2 != B[i][j]) {
				for (int k = 0; k < 3; k++)
					for (int l = 0; l < 3; l++)
						d[i + k][j + l]++;
				sum++;
			}
		}
		// 더 이상 i번째 행에서 행렬 변환 연산 불가
		// 이때 i번째 행 전체는 A와 B가 동일해야 함, 동일하지 않으면 -1 출력 후 종료
		for (int j = 0; j < m; j++) {
			if ((A[i][j] + d[i][j]) % 2 != B[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	// 맨 아래 두 행은 검증이 안되었으므로 마저 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((A[i][j] + d[i][j]) % 2 != B[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << sum;
}
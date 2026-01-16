#include <iostream>
using namespace std;

int pal[2001][2001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, arr[2001];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> m;

	for (int i = 0; i < n; i++) {  // i는 s로부터의 거리, 즉 s + i = e
		for (int j = 1; j <= n; j++) {  // j는 시작점 s
			if (i + j > n) break;  // 배열 범위 준수
			if (!i) pal[j][j + i] = 1;  // s와 e가 같으면 무조건 팰린드롬
			else if (i == 1 && arr[j] == arr[j + i])  // 길이가 2이고 두 문자가 동일하면 팰린드롬
				pal[j][j + i] = 1;
			else if (i > 1) {  // 길이가 3 이상일 때, 양끝이 같고 그 둘을 제외했을 때 팰린드롬이면 팰린드롬
				if (arr[j] == arr[j + i] && pal[j + 1][j + i - 1])
					pal[j][j + i] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << pal[s][e] << "\n";
	}
}
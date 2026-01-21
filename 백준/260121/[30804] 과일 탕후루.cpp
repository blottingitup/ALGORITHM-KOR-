#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t[200000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i];

	// 탕후루의 왼쪽 끝 index는 start, 오른쪽 끝 index는 end
	int start = 0, end = 0;
	int a = t[0], b = 0, f[10] = { 0, }, max_len = 1;  // a, b는 현재 과일, f는 과일 개수
	f[t[start]] = 1;
	while (1) {
		end++;  // 오른쪽 한계를 1 늘림
		if (end == n) break;  // 늘리는 게 불가능
		if (!b && t[end] != a) {  // 원래 과일 1종, 새로운 과일 추가
			b = t[end];
			f[b] = 1;
		}
		else if (b && t[end] != a && t[end] != b) {  // 과일 2종인데 새로운 과일 추가
			while (f[a] && f[b])  // 과일 한 종류가 다 없어질 때까지 start를 오른쪽으로 이동
				f[t[start++]]--;
			if (f[a] == 0) {
				a = b;
				f[a] = f[b];
			}
			b = t[end];  // 새로운 과일 종류 기록
			f[b] = 1;
		}
		else f[t[end]]++;  // 기존 과일 중 하나: 과일 개수 증가
		max_len = max(max_len, end - start + 1);
	}
	cout << max_len;
}
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, temp, coin[101] = { 0, }, value[10001] = { 0, };
	set<int> c;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		c.insert(temp);
	}
	temp = 1;
	for (auto iter = c.begin(); iter != c.end(); iter++)  // 동전 중복 제거, 오름차순 정렬
		coin[temp++] = *iter;

	for (int i = 1; i <= k; i++)
		value[i] = k + 1;  // 최솟값 비교를 위한 초기화
	for (int i = 1; i < temp; i++) {  // 모든 동전에 대해 비교
		for (int j = 1; j <= k; j++) {
			if (coin[i] > j) continue;  // 값 비교 의미 없음
			else if (coin[i] == j) value[j] = 1;  // 동전 하나에 대응되는 값
			else value[j] = min(value[j], value[j - coin[i]] + 1);  // DP
		}
	}

	if (value[k] == k + 1) cout << -1;
	else cout << value[k];
}
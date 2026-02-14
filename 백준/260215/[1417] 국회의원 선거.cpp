#include <iostream>
#include <utility>
using namespace std;

int num[51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, change = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];

	while (1) {
		pair<int, int> max_diff = { -1, -1 };  // {번호, 뺏어야 하는 득표 수}
		for (int i = 2; i <= n; i++) {
			if (num[i] >= num[1] && num[i] - num[1] + 1 > max_diff.second)
				max_diff = { i, num[i] - num[1] + 1 };
		}
		if (max_diff.first == -1 && max_diff.second == -1) break;  // 모든 득표수가 1번보다 낮음
		num[1]++;
		num[max_diff.first]--;
		change++;
	}
	cout << change;
}
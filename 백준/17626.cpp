#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ch = 2;
	vector<int> lag(2);
	cin >> n;
	// 1은 1로, 나머지는 전부 4로 초기화
	lag[1] = 1;
	for (int i = 2; i <= n; i++)
		lag.push_back(4);
	for (int i = 2; i <= n; i++) {
		if (i == ch * ch) {  // 제곱수 판정
			lag[i] = 1;
			ch++;
		}
		else {  // 제곱수가 아닐 때 현재 숫자에서 제곱수를 뺀 것에 1을 더한 것이 개수
			for (int j = 1; j < ch; j++) {
				lag[i] = min(lag[i], lag[i - j * j] + 1);
			}
		}
	}
	cout << lag[n];
}
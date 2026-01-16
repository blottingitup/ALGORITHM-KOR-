#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, sum = 0;
	string target;
	cin >> target >> n;
	for (int i = 0; i < n; i++) {
		string ring;
		cin >> ring;
		ring += ring;  // 한바퀴 돌아서 문자열 인식되게 복사본을 이어붙임
		for (int j = 0; j < ring.size(); j++) {
			int k;
			for (k = 0; k < target.size(); k++)  // 시작점 j부터 문자열과 반지 대조
				if (ring[j + k] != target[k]) break;
			// 위쪽 반복문에 break가 없다는 것은 문자열과 일치하는 부분이 있다는 것
			if (k == target.size()) {
				sum++;
				break;
			}
		}
	}
	cout << sum;
}
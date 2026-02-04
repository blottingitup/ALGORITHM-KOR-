#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	if (!(n % 2) || !(n % 5)) cout << -1;  // N이 2나 5의 배수면 해 없음
	else {  // N이 2나 5의 배수가 아니면 무조건 해가 존재
		int num_len = to_string(n).length();  // N의 자릿수
		int num = 1, mul = 1;
		for(int i = 1; i < num_len; i++)  // N의 자릿수와 동일한 1로만 이루어진 수 만들기
			num += (mul *= 10);

		for (mul = num_len; ; mul++) {  // i는 1로만 이루어진 수의 자릿수
			if (!(num % n)) break;  // 나누어 떨어지면 break
			num = ((num % n) * 10 + 1) % n;  // mod 연산의 성질
		}
		cout << mul;
	}
}
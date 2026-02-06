#include <iostream>
using namespace std;

// 규칙성에 따라 M = 3, 4, 5인 경우의 수는 서로 이어붙일 수 있음
int c3(int start) {
	for (int i = 0; i < 6; i++) {
		int a = i % 2 + 1;
		int b = i % 3 + 1;
		cout << a << " " << b + start - 1 << "\n";
	}
	return (start + 3);
}

int c4(int start) {
	for (int i = 0; i < 8; i++) {
		int a = i % 2 + 1, b;
		if (i == 0 || i == 5) b = 1;
		else if (i == 1 || i == 4) b = 2;
		else if (i == 3 || i == 6) b = 3;
		else b = 4;
		cout << a << " " << b + start - 1 << "\n";
	}
	return (start + 4);
}

int c5(int start) {
	for (int i = 0; i < 10; i++) {
		int a = i % 2 + 1, b;
		if (i == 0 || i == 5) b = 1;
		else if (i == 4 || i == 7) b = 2;
		else if (i == 1 || i == 6) b = 3;
		else if (i == 3 || i == 8) b = 4;
		else b = 5;
		cout << a << " " << b + start - 1 << "\n";
	}
	return (start + 5);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;
	if (m <= 2) cout << "NO";  // 2 이하는 불가능, 나머지는 3, 4, 5의 합으로 모든 수 구현 가능
	else if (m % 3 == 0) {  // 3의 합
		cout << "YES\n";
		int s = 1;
		while (s <= m) {
			s = c3(s);
		}
	}
	else if (m % 3 == 1) {  // 3과 4의 합
		cout << "YES\n";
		int s = 1;
		while (s + 4 < m) {
			s = c3(s);
		}
		s = c4(s);
	}
	else {  // 3과 5의 합
		cout << "YES\n";
		int s = 1;
		while (s + 5 < m) {
			s = c3(s);
		}
		s = c5(s);
	}
}
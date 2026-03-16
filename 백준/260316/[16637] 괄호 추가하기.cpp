#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_sum = INT32_MIN;
vector<int> num;
vector<char> op;

int solve(int a, char operand, int b) {  // 사칙연산
	switch (operand) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
}

// 괄호 안에는 하나의 연산자만이 들어갈 수 있음
void whole(int pos, int sum) {  // 연산자 위치, 현재까지 계산된 값
	if (pos >= op.size()) {  // 남은 연산자 전부 소진
		max_sum = max(max_sum, sum);
		return;
	}

	whole(pos + 1, solve(sum, op[pos], num[pos + 1]));  // 현재 위치 바로 계산

	if (pos + 2 <= op.size()) {  // 현재 위치 다음의 연산자에 우선순위 주기
		int temp = solve(num[pos + 1], op[pos + 1], num[pos + 2]);  // pos + 1 위치에 괄호를 넣어서 먼저 계산
		whole(pos + 2, solve(sum, op[pos], temp));  // 왼쪽에서부터 먼저 계산하므로 pos 위치를 다음에 바로 계산
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c >= '0' && c <= '9') num.push_back(c - '0');
		else op.push_back(c);
	}

	whole(0, num[0]);
	cout << max_sum;
}
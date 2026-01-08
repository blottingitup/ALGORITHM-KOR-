#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int A[101];
vector<string> op;

void make_op(int dep, string op_init) {  // 연산자로 순열 만들고 op vector에 저장
	if (dep == op_init.size()) {
		op.push_back(op_init);
		return;
	}
	for (int i = dep; i < op_init.size(); i++) {
		swap(op_init[i], op_init[dep]);
		make_op(dep + 1, op_init);
		swap(op_init[i], op_init[dep]);
	}
}

int result_op(string op_str) {  // make_op에서 구한 연산자 조합에 대한 계산 결과 반환
	int res = A[0];
	for (int i = 0; i < op_str.size(); i++) {
		switch (op_str[i]) {
			case '+':
				res += A[i + 1];
				break;
			case '-':
				res -= A[i + 1];
				break;
			case '*':
				res *= A[i + 1];
				break;
			case '/':
				res /= A[i + 1];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, op_four[4], op_flag = 0, min = INT32_MAX, max = INT32_MIN;
	string op_init = "";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> op_four[i];

	for (int i = 0; i < n - 1; i++) {  // 가능한 연산자들을 전부 묶어서 하나의 string으로 표현
		while (!op_four[op_flag])
			op_flag++;
		switch (op_flag) {
			case 0:
				op_init += "+";
				break;
			case 1:
				op_init += "-";
				break;
			case 2:
				op_init += "*";
				break;
			case 3:
				op_init += "/";
				break;
		}
		op_four[op_flag]--;
	}

	make_op(0, op_init);
	for (int i = 0; i < op.size(); i++) {
		int res = result_op(op[i]);
		if (res > max) max = res;
		if (res < min) min = res;
	}
	cout << max << "\n" << min;
}
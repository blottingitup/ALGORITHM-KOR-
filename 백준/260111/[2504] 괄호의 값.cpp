#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;

	bool flag = true;
	vector<int> val;
	vector<char> ss;
	for (int i = 0; i < s.size(); i++) {
		// 올바른 괄호열 판별
		if (s[i] == '(') {
			ss.push_back(s[i]);
			val.push_back(-2);  // 소괄호는 -2 삽입
		}
		else if (s[i] == '[') {
			ss.push_back(s[i]);
			val.push_back(-3);  // 대괄호는 -3 삽입
		}
		else if (s[i] == ')') {
			if (!ss.empty() && ss.back() == '(')  ss.pop_back();  // 올바른 괄호열
			else {  // 올바르지 않은 괄호열
				flag = false;
				break;
			}
		}
		else if (s[i] == ']') {
			if (!ss.empty() && ss.back() == '[')  ss.pop_back();  // 올바른 괄호열
			else {  // 올바르지 않은 괄호열
				flag = false;
				break;
			}
		}

		// 올바른 괄호열일 때 값 계산
		// 닫는 괄호가 들어올 때: 음수가 있으면 양수로 변환, 양수가 있으면 곱셈
		// 양수가 있다는 것은 괄호를 연속으로 닫았다는 의미이므로 곱한다
		// 각 반복마다 스택의 위에서부터 양수는 전부 더한다
		
		// 곱셈
		if (s[i] == ')') {
			if (val.back() == -2) val.back() = 2;  // 단일 소괄호
			else {
				int temp = val.back();
				val.pop_back();
				val.back() *= -temp;
			}
		}
		else if (s[i] == ']') {
			if (val.back() == -3) val.back() = 3;  // 단일 대괄호
			else {
				int temp = val.back();
				val.pop_back();
				val.back() *= -temp;
			}
		}
		// 덧셈
		for (int i = val.size() - 1; i > 0; i--) {
			if (val[i] > 0 && val[i - 1] > 0) {
				val[i - 1] += val[i];
				val.pop_back();
			}
		}
	}
	if (!flag || !ss.empty()) cout << 0;  // 올바르지 않은 괄호열
	else cout << val[0];
}
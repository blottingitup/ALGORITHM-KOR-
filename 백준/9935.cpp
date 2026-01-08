#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, bomb;
	vector<char> ss;
	deque<int> ch;
	cin >> s >> bomb;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		ss.push_back(s[i]);
		if (s[i] == bomb[0] || s[i] != bomb[cnt]) {  // 폭탄 내부 문자열은 중복 없음
			cnt = 0;  // 폭탄과 관련 없음
			if (s[i] == bomb[0]) cnt = 1;  // 폭탄 시작점
		}
		else cnt++;  // 연속으로 폭탄과 유사
		ch.push_back(cnt);  // 폭발 검사 위치 저장

		if (cnt == (int)bomb.size()) {  // 폭발
			for (int j = 0; j < bomb.size(); j++) {  // 폭탄 하나를 전부 pop
				ss.pop_back();
				ch.pop_back();
			}
			// 폭탄 검사 위치 갱신
			if (ch.size()) cnt = ch.back();
			else cnt = 0;
		}
	}

	if (!ss.size()) cout << "FRULA";
	else
		for (int i = 0; i < ss.size(); i++)
			cout << ss[i];
}
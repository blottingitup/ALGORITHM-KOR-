#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 1; i <= s[0].size(); i++) {
		set<string> ss;
		for (int j = 0; j < n; j++)  // 길이 i의, 뒤에서부터 자른 부분 문자열을 set에 삽입
			ss.insert(s[j].substr(s[0].size() - i, i));
		if (ss.size() == n) {  // 중복된 부분 문자열이 없으면 set의 크기 == 학생 수
			cout << i;
			break;
		}
	}
}
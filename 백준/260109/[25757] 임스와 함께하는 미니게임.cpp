#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s, temp;
	set<string> ss;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ss.insert(temp);  // set으로 중복 제거
	}
	// 자신 포함 2, 3, 4명이므로 그에 따라 필요 인원수 계산
	if (s == "Y") cout << ss.size();
	else if (s == "F") cout << ss.size() / 2;
	else if (s == "O") cout << ss.size() / 3;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		vector<char> ss;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (ss.empty()) ss.push_back(s[j]);  // 스택이 비어있으면 무조건 push
			else {
				if (s[j] == ss.back()) ss.pop_back();  // top이랑 같으면 pop
				else ss.push_back(s[j]);  // 다르면 push
			}
		}
		if (ss.empty()) sum++;  // 쌍을 지었을 때 모두 교차하지 않게 묶이면 전부 pop되어 empty
	}
	cout << sum;
}
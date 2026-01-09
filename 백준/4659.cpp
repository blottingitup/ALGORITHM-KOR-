#include <iostream>
#include <string>
using namespace std;

bool ch_vowel(char c) {
	if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	while (s != "end") {
		int v_sum = 0, c_sum = 0;
		bool ok = true, has_vowel = false, ee = false, oo = false;
		for (int i = 0; i < s.size(); i++) {
			if (i && s[i] == s[i - 1]) {
				if (s[i] == 'e') {  // ee
					if (i + 1 < s.size() && s[i + 1] == 'e') {  // e도 3개 이상은 불가능
						ok = false;
						break;
					}
				}
				else if (s[i] == 'o') {  // oo
					if (i + 1 < s.size() && s[i + 1] == 'o') {  // o도 3개 이상은 불가능
						ok = false;
						break;
					}
				}
				else {  // e와 o 외 다른 글자는 연속 불가능
					ok = false;
					break;
				}
			}
			if (ch_vowel(s[i])) {
				has_vowel = true;
				v_sum++;
				c_sum = 0;
			}
			else {
				c_sum++;
				v_sum = 0;
			}
			if (v_sum >= 3 || c_sum >= 3) {  // 모음이나 자음이 연속으로 3개 미만
				ok = false;
				break;
			}
		}
		if (!has_vowel) ok = false;  // 모음은 적어도 하나 이상 포함해야 함
		if (ok) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
		cin >> s;
	}
}
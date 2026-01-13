#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int min = INT32_MAX;
	string s;
	cin >> s;
	int bound = s.size() / 3 < 9 ? s.size() / 3 : 9;  // 최대 자릿수는 9자리, 문자열 길이 / 3 중 작은 쪽
	for (int i = 1; i <= bound; i++) {
		int cur_len = i, cur_pos = 0, d = 0, fa = 0;

		// 문자열에서 숫자 길이만큼 가져오기
		if (s[cur_pos] == '0') continue;  // 0으로 시작하는 숫자는 불가
		string temp = s.substr(cur_pos, cur_len);
		int num = stoi(temp);
		cur_pos += cur_len;
		int init_pos = cur_pos;

		// 가능한 두 번째 숫자를 찾고 등차를 찾음
		int cur_bound = (s.size() - cur_len) / 2 < 9 ? (s.size() - cur_len) / 2 : 9;
		for (int k = cur_len; k <= cur_bound; k++) {
			if (init_pos + k >= s.size()) break;  // 3번째 항이 올 수 없으므로 불가
			if (s[init_pos] == '0') continue;  // 0으로 시작하는 숫자는 불가
			vector<int> prop;
			cur_pos = init_pos;
			num = stoi(temp);
			string temp2 = s.substr(cur_pos, k);
			if (s[cur_pos + k] == '0') continue;  // 0으로 시작하는 숫자는 불가
			int num2 = stoi(temp2);
			d = num2 - num;
			if (d <= 0) continue;  // 공차는 양수만 허용

			// 등차를 찾았으므로 반복
			prop.push_back(num);
			prop.push_back(num2);
			num = num2;
			cur_pos += k;
			cur_len = to_string(num + d).size();

			while (cur_pos < s.size()) {
				// 일단 최대한 큰 수를 마지막 수로 잡는다
				// 그리고 f_A를 확인한 다음 등차에 의한 새로운 항을 찾고 반복
				string end = s.substr(cur_pos);
				if (end.size() <= 9 && end[0] != '0') {
					int end_num = stoi(end);
					if (end_num % num == 0 && end_num / num >= 2) {
						fa = end_num / num;
						if (fa < min) min = fa;
					}
				}

				int next_val = num + d;
				if (next_val >= 1000000000) break;
				string next_s = to_string(next_val);
				int next_len = next_s.size();

				if (cur_pos + next_len < s.size() && s.substr(cur_pos, next_len) == next_s) {
					prop.push_back(next_val);
					num = next_val;
					cur_pos += next_len;
				}
				else break;
			}
		}
	}
	if (min == INT32_MAX) cout << 0;
	else cout << min;
}
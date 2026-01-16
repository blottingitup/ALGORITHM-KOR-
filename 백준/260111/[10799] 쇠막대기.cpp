#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	vector<char> ss;
	vector<int> num;
	cin >> s;

	int laser_num = 0, iron_num = 0, tot = 0;
	for (int i = 0; i < s.size(); i++) {
		ss.push_back(s[i]);
		if (s[i] == '(') {
			iron_num++;
			num.push_back(0);  // 레이저 맞은 횟수
		}
		else if (s[i] == ')') {
			if (i && s[i - 1] == ')') {  // 쇠막대기
				tot += num.back() + 1;  // 잘린 막대 개수 누적
				num.pop_back();
				if (num.empty()) laser_num = 0;  // 쇠막대기가 없으면 레이저 개수 초기화
			}
			else {  // 레이저
				iron_num--;
				laser_num++;
				// 현재 있는 쇠막대기 전체에 레이저 적용
				for (auto iter = num.begin(); iter != num.end(); iter++)
					(*iter)++;
				num.pop_back();
			}
		}
	}
	cout << tot;
}
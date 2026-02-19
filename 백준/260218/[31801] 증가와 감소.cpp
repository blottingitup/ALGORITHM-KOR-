#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ch[1000001];  // ch[i]는 i까지의 증가 후 감소하는 수의 누적 개수

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 120; i <= 1000000; i++) {  // 120부터 조건 만족 가능
        string s = to_string(i);
        bool is_up = false, is_down = false, suc = true;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == s[j - 1]) {  // 숫자가 연속으로 같을 수 없음
                suc = false;
                break;
            }
            if (!is_up && !is_down) {  // 앞쪽에 증가 부분 존재
                if (s[j] > s[j - 1]) is_up = true;
                else {
                    suc = false;
                    break;
                }
            }
            else if (is_up && !is_down && s[j] < s[j - 1])  // 증가 부분이 확인되고 감소 부분도 존재
                is_down = true;
            else if (is_down) {  // 감소 부분에 위배되는지 확인
                if (s[j] >= s[j - 1]) {
                    suc = false;
                    break;
                }
            }
        }
        if (!suc || !is_down) ch[i] = ch[i - 1];  // 조건 위배 혹은 감소 부분이 없었다면 증가 X
        else ch[i] = ch[i - 1] + 1;
    }

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        cout << ch[b] - ch[a - 1] << "\n";
    }
}
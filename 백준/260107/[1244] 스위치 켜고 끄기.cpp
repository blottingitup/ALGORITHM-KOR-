#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, stu, num;
	bool sw[101];
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> sw[i];
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> stu >> num;
		if (stu == 1) {  // 남학생
			int temp = num;
			while (temp <= n) {
				sw[temp] = !sw[temp];  // 스위치 변경
				temp += num;  // 주어진 수의 배수
			}
		}
		else {  // 여학생
			sw[num] = !sw[num];  // 일단 주어진 숫자의 스위치 변경
			int left = num - 1, right = num + 1;  // 주어진 숫자의 좌우
			while (left >= 1 && right <= n && sw[left] == sw[right]) {  // 범위 내에서 대칭
				// 스위치 변경
				sw[left--] = !sw[left];
				sw[right++] = !sw[right];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << sw[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}
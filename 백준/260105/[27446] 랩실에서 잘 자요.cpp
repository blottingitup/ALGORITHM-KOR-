#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp, ink = 7;
	bool page[101] = { false, };
	vector<int> left;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		page[temp] = true;
	}
	for (int i = 1; i <= n; i++)  // 잃어버린 페이지 확인
		if (!page[i]) left.push_back(i);

	if (!left.size()) cout << 0;  // 잃어버린 페이지가 없을 때
	else {
		// 이전 페이지와의 페이지 수 차이를 계산해서 연속 출력할지, 따로 출력할지 선택
		for (int i = 1; i < left.size(); i++) {
			ink += (7 < 2 * (left[i] - left[i - 1]) ? 7 : 2 * (left[i] - left[i - 1]));
		}
		cout << ink;
	}
}
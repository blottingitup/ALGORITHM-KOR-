#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp;
	vector<int> sol;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sol.push_back(temp);
	}
	sort(sol.begin(), sol.end());
	
	int left = 0, right = n - 1;
	int best_al = left, best_ac = right;
	int sum = 2000000001;
	while (left < right) {  // 투 포인터
		// 특성값이 더 작은 게 발견되면 인덱스와 특성값
		if (abs(sol[left] + sol[right]) < sum) {
			best_al = left;
			best_ac = right;
			sum = abs(sol[left] + sol[right]);
		}
		// 절댓값이 큰 쪽의 포인터를 이동
		if (sum == 0) break;
		else if (abs(sol[left]) > abs(sol[right]))
			left++;
		else right--;
	}
	cout << sol[best_al] << " " << sol[best_ac];
}
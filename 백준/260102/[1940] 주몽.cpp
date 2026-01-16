#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp, sum = 0;
	vector<int> armor;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		armor.push_back(temp);
	}
	sort(armor.begin(), armor.end());  // 오름차순 정렬

	int left = 0, right = armor.size() - 1;  // 정렬된 양끝의 두 원소의 합을 구함
	while (left < right) {
		if (armor[left] + armor[right] == m) {  // 합이 m이 되면 갑옷 제작 가능, vector에서 제거
			sum++;
			remove(armor.begin(), armor.end(), armor[left]);
			remove(armor.begin(), armor.end(), armor[(right--) - 1]);
		}
		else if (armor[left] + armor[right] < m)  // 합이 m보다 작으므로 더 큰 값을 활용
			left++;
		else right--;  // 합이 m보다 크므로 더 작은 값을 활용
	}
	cout << sum;
}
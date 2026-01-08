#include <iostream>
#include <algorithm>
#include <deque>
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

	int left = 0, right = armor.size() - 1;
	while (left < right) {
		if (armor[left] + armor[right] == m) {
			sum++;
			armor.erase(armor.begin() + left);
			armor.erase(armor.end() - right - 1);
		}
		else if (armor[left] + armor[right] < m)
			left++;
		else right--;
	}
	cout << sum;
}
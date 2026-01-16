#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	long long int sum = 0;
	vector<int> garden;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (garden.empty()) garden.push_back(temp);  // 스택이 비어있을 때 무조건 push
		else if (temp < garden.back()) {  // 지금 들어오는 건물이 가장 낮을 때 push
			sum += garden.size();  // 현재 스택의 모든 건물들은 이 건물의 정원을 볼 수 있음
			garden.push_back(temp);
		}
		else {  // 지금 들어오는 건물보다 낮은 건물이 있을 때, 그것들을 전부 pop
			while (!garden.empty() && temp >= garden.back())
				garden.pop_back();
			if (garden.empty()) garden.push_back(temp);  // 지금까지 가장 높은 건물이면 전부 pop됨
			else {  // 아니면 위와 마찬가지로 현재 스택의 모든 건물들은 이 건물의 정원을 볼 수 있음
				sum += garden.size();
				garden.push_back(temp);
			}
		}
	}
	cout << sum;
}
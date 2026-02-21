#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	if (!a) {  // y = C 꼴
		if (c % b == 0) {
			for (int i = 1; i <= 10; i++)
				arr[i].push_back(c / b);
		}
	}
	else if (!b) {  // x = C 꼴
		if (c % a == 0) {
			for (int i = 1; i <= 10; i++)
				arr[c / a].push_back(i);
		}
	}
	else {
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (a * i + b * j == c)
					arr[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= 10; i++) {
		if (arr[i].empty()) cout << 0 << "\n";
		else {
			for (int j : arr[i])
				cout << j << " ";
			cout << "\n";
		}
	}
}
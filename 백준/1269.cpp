#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, sa = 0, sb = 0, temp;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < b; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int> diff1(A.size() + B.size()), diff2(A.size() + B.size());
	set_difference(A.begin(), A.end(), B.begin(), B.end(), diff1.begin());
	set_difference(B.begin(), B.end(), A.begin(), A.end(), diff2.begin());

	for (auto x : diff1) {
		if (!x) break;
		sa++;
	}
	for (auto x : diff2) {
		if (!x) break;
		sb++;
	}

	cout << sa + sb;
}
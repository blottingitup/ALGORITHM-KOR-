#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0, num[10] = { 0, };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		num[s[i] - '0']++;
	if ((num[6] + num[9]) % 2) sum = (num[6] + num[9]) / 2 + 1;
	else sum = (num[6] + num[9]) / 2;
	for (int i = 0; i < 9; i++) {
		if (i == 6) continue;
		if (num[i] > sum) sum = num[i];
	}
	cout << sum;
}
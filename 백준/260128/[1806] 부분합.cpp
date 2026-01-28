#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
ll num[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, s, sum = 0;
	int len = 0;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> num[i];

	int end = 1;
	for (int start = 1; start <= n; start++) {
		while (sum < s && end <= n) sum += num[end++];
		if (sum >= s) {
			if (!len) len = end - start;
			else len = min(len, end - start);
		}
		sum -= num[start];
	}
	cout << len;
}
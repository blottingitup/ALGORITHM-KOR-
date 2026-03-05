#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		vector<int> st;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			st.push_back(temp);
		}

		int max = st[n - 1];
		ll sum = 0;
		for (int j = n - 2; j >= 0; j--) {
			if (st[j] > max) {  // 뒤에서부터 최댓값 갱신
				max = st[j];
				continue;
			}
			sum += (ll)(max - st[j]);
		}
		cout << sum << "\n";
	}
}
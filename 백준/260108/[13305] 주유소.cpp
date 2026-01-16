#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, temp, tot = 0;
	vector<ll> len, price;
	cin >> n;
	for (ll i = 1; i < n; i++) {
		cin >> temp;
		len.push_back(temp);
	}
	for (ll i = 0; i < n; i++) {
		cin >> temp;
		price.push_back(temp);
	}

	ll cur_price = price[0], cur_len = 0;
	for (ll i = 0; i < n - 1; i++) {
		cur_len += len[i];
		if (i == n - 2) {  // 맨 마지막은 그냥 계산
			tot += cur_price * cur_len;
		}
		else if (cur_price > price[i + 1]) {  // 현재 도시보다 다음 도시의 가격이 싸질때까지 누적
			tot += cur_price * cur_len;
			cur_price = price[i + 1];
			cur_len = 0;
		}
	}
	cout << tot;
}
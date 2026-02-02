#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

typedef long long int ll;
vector<tuple<ll, ll, ll>> b(500002);  // 왼쪽 위치, 크기, 오른쪽 위치

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll temp;
		cin >> temp;
		b[i] = { i - 1, temp, i + 1 };  // tuple로 이루어진 vector를 연결 리스트로 활용
	}
	b[0] = { -1LL, (ll)1e18, 1LL};  // head

	while (1) {
		ll left1, s1, right1;
		auto [x, y, z] = b[0];
		tie(left1, s1, right1) = b[z];  // 연결 리스트 첫 번째 원소
		if (right1 == n + 1) {  // 연결 리스트에 원소가 1개만 남은 경우 완료
			cout << s1 << "\n" << z;
			break;
		}

		while (1) {  // 연결 리스트 순회
			tie(left1, s1, right1) = b[z];
			ll sum = s1;
			auto [left0, s0, right0] = b[left1]; // 왼쪽 원소 비교
			if (s1 >= s0) {
				b[z] = { left0, s1, right1 };
				get<2>(b[left0]) = z;
				sum += s0;
			}

			tie(left1, s1, right1) = b[z];
			if (right1 == n + 1) {  // 맨 오른쪽에 도달해서 오른쪽 탐색 불가
				b[z] = { left1, sum, right1 };
				break;
			}
			auto [left2, s2, right2] = b[right1];  // 오른쪽 원소 비교
			if (s1 >= s2) {
				b[z] = { left1, s1, right2 };
				get<0>(b[right2]) = z;
				sum += s2;
			}

			// 오른쪽으로 이동
			tie(left1, s1, right1) = b[z];
			b[z] = { left1, sum, right1 };
			if (right1 == n + 1) break;
			z = right1;
		}
	}
}
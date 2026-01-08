#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, k, max_val, current_max_val = 0, before_max_loc = 0, A[100001] = { 0, };
	cin >> n;

	// 앞에 있는 수가 뒤에 있는 수보다 클 경우에 비내림차순이 안됨
	// 우선 비내림차순이 되는 최소 횟수를 탐색
	for (auto i = 0; i < n; i++) {
		cin >> A[i];
		if (!i) max_val = A[i];
		else {
			if (A[i] < max_val) {  // 비내림차순 성립 안함
				before_max_loc = i + 1;  // 숫자가 증가할 위치 저장
				current_max_val = max_val;  // 비내림차순이 성립 안하는 순간의 최댓값 저장
			}
			if (A[i] > max_val) max_val = A[i];  // 최댓값 저장
		}
	}
	cin >> k;

	// 비내림차순이 성립 안하는 순간까지의 모든 값을 그 구간에서의 최댓값으로 통일
	// 최초의 비내림차순 수열을 만든다
	ll realsum = 0;
	for (auto i = 0; i < before_max_loc; i++) {
		realsum += current_max_val - A[i];
		A[i] = current_max_val;
	}

	// 이제 비내림차순이 되어서 앞에서부터 숫자를 늘리면 된다
	// 앞에서부터 동일한 숫자가 몇 개인지 센다
	vector<pair<ll, ll>> same;  // { 숫자, 누적 개수 }
	same.push_back({ A[0], 1 });
	for (auto i = 0; i < n - 1; i++) {
		if (A[i] == A[i + 1])
			same.back().second++;
		else same.push_back({A[i + 1], same.back().second + 1});
	}
	/*for (auto x : same) {
		auto [a, b] = x;
		cout << a << " " << b << "\n";
	}*/

	ll idx = 0, tot = 0, diff = 0;
	if (k - realsum >= 0 && realsum > 0) tot++;  // 최초의 내림차순 반영
	while (realsum <= k) {
		if (idx < (ll)same.size() - 1) {  // 가장 작은 수들이 그 다음으로 작은 수와 같아진다
			diff = same[idx + 1].first - same[idx].first;
			if (k - realsum >= diff * same[idx].second) {  // 가장 작은 수 전부 평탄화 가능
				realsum += diff * same[idx].second;
				tot += diff;
			}
			else {  // 평탄화 불가능
				tot += (k - realsum) / same[idx].second;  // 모든 숫자가 1씩 증가했을 때 비내림차순 1회 증가
				k = 0;  // 맨 마지막 조건문 건너뛰기
				break;
			}
			idx++;  // 다음 숫자 평탄화 실시
		}
		else break;  // 모든 숫자가 같아지고 버튼을 더 누를 수 있을 때
	}
	if (k - realsum > 0) tot += (k - realsum) / n;  // 한 번 비내림차순이 되려면 n회 필요
	cout << tot;
}
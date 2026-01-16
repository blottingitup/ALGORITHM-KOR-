#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long int ll;
ll cho[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp, max = 0;
	ll sum = 0;
	set<int> sep;
	vector<int> h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > max) max = temp;
		h.push_back(temp);
		sep.insert(temp);
	}
	for (int i = 0; i < n; i++) {  // 세로가 같은 조각끼리 합치고
		cin >> temp;
		cho[h[i]] += temp;
	}

	// 바로 아래 단계의 세로로 쪼개서 총 크기가 커지는지 확인
	sum = max * cho[max];
	int h_before = max, now_w = cho[max];
	for (auto iter = sep.rbegin(); iter != sep.rend(); iter++) {
		if (iter == sep.rbegin()) continue;
		int h_now = *iter;
		// 초콜릿 쪼개기
		cho[h_now] += cho[h_before];
		//cho[h_before - h_now] += cho[h_before];
		h_before = h_now;
		if (sum < h_now * cho[h_now]) sum = h_now * cho[h_now];
	}
	cout << sum;
}
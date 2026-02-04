#include <iostream>
#include <queue>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, temp;
	priority_queue<ll> pq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		pq.push(-temp);  // 작은 순서대로 정렬
	}

	for (int i = 0; i < m; i++) {
		ll a = -pq.top();  // 가장 작은 수 가져옴
		pq.pop();
		ll b = -pq.top();  // 그 다음으로 작은 수 가져옴
		pq.pop();

		pq.push(-(a + b)), pq.push(-(a + b));  // 두 수를 더해서 다시 pq에 삽입
	}

	ll sum = 0;
	while (!pq.empty()) {  // pq에 있는 수들의 합
		sum += (ll)pq.top();
		pq.pop();
	}
	cout << -sum;
}
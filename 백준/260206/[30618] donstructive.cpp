#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p;
	deque<int> d;
	cin >> n;
	p = n % 2;
	for (int i = n; i >= 1; i--) {  // 번갈아가며 deque의 앞뒤로 큰 수부터 삽입하면 큰 수가 중앙에 모임
		if (i % 2 == p) d.push_back(i);
		else d.push_front(i);
	}
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
}
#include <iostream>
#include <cmath>
using namespace std;

typedef long long int ll;

// N번째 원반을 옮길 때: 1~N-1을 1->2, N을 1->3, 1~N-1을 2->3
void hanoi(int n, int start, int end, int mid) {
	if (n == 1) {
		cout << start << " " << end << "\n";
		return;
	}
	hanoi(n - 1, start, mid, end);
	cout << start << " " << end << "\n";
	hanoi(n - 1, mid, end, start);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cout << (ll)(pow(2, n)) - 1LL << "\n";
	hanoi(n, 1, 3, 2);
}
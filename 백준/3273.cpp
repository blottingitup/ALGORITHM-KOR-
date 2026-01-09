#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, x, sum = 0, arr[100000] = { 0, };
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cin >> x;
	ll left = 0, right = n - 1;
	while (left < right) {  // 위에서 정렬 후 투 포인터
		if (arr[left] + arr[right] < x) left++;
		else if (arr[left] + arr[right] > x) right--;
		else {
			sum++;
			left++;
			right--;
		}
	}
	cout << sum;
}
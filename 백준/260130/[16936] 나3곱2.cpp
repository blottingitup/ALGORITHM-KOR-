#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long int ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, muldiv[100];
	vector<ll> num, no_three;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll temp;
		cin >> temp;
		if (temp % 3 && !(temp % 2)) no_three.push_back(temp);
		else num.push_back(temp);
	}
	// 3의 배수가 아니고 2의 배수인 숫자들은 반드시 오름차순으로 맨 끝에 존재
	if(!no_three.empty()) sort(no_three.begin(), no_three.end());
	for (ll i = 0; i < no_three.size(); i++)
		muldiv[i + n - no_three.size()] = no_three[i];

	// 3의 배수가 아니고 2의 배수인 숫자들을 제외하고 맨 뒤의 숫자를 하나 정함
	// 브루트 포스로 연산 가능한지 전부 시도
	// 뒤에서부터 시작하므로 연산 조건은 역으로 나누기 2가 가능한지 확인
	ll end = n - no_three.size() - 1, end1 = end;
	for (int i = 0; i < n - no_three.size(); i++) {
		muldiv[end1] = num[i];  // 초기화
		bool success = true;
		for (int j = 1; j < n - no_three.size(); j++) {
			if (!(muldiv[end1] % 2) && find(num.begin(), num.end(), muldiv[end1] / 2) != num.end()) {  // 곱2 연산 성공
				end1--;
				muldiv[end1] = muldiv[end1 + 1] / 2;
			}
			else {  // 곱2 연산 실패, 나3 연산 시도
				if (find(num.begin(), num.end(), muldiv[end1] * 3) != num.end()) {
					end1--;
					muldiv[end1] = muldiv[end1 + 1] * 3;
				}
				else {  // 전부 실패시 배열 초기화 후 다음 숫자 시도
					fill(muldiv, muldiv + end1 + 1, 0);
					end1 = end;
					success = false;
					break;
				}
			}
		}
		if (success) break;
	}

	for (int i = 0; i < n; i++)
		cout << muldiv[i] << " ";
}
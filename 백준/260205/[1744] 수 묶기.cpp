#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, temp, sum = 0;
	bool zero = false;
	priority_queue<int> pq_minus, pq_plus;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp > 0) pq_plus.push(temp);
		else if (temp < 0) pq_minus.push(-temp);
		else zero = true;
	}

	int plus = 0, minus = 0;
	while (!pq_plus.empty()) {  // 양수 pq
		int a = pq_plus.top();
		pq_plus.pop();
		if (pq_plus.empty()) {  // 양수인 수가 홀수개면 마지막 1개를 남겨서 저장
			plus = a;
			break;
		}
		else {  // 가장 큰 양수들끼리 곱해서 더함
			int b = pq_plus.top();
			pq_plus.pop();
			sum += (a * b > a + b ? a * b : a + b);  // 양수는 충분히 작으면 더하는 것이 더 클 수도 있음
		}
	}
	while (!pq_minus.empty()) {  // 음수 pq
		int a = pq_minus.top();
		pq_minus.pop();
		if (pq_minus.empty()) {  // 음수인 수가 홀수개면 마지막 1개를 남겨서 저장
			minus = -a;  // 음수를 양수로 pq에 넣었으므로 뺄 때는 부호 반전
			break;
		}
		else {  // 가장 큰 음수들끼리 곱해서 더함
			int b = pq_minus.top();
			pq_minus.pop();
			sum += a * b;  // 음수는 무조건 곱하는 것이 더 큼
		}
	}

	// 남는 수에 대한 처리: 남는 수가 없으면 0의 존재와 무관하게 필요없음
	if (!minus && plus)  // 양수는 남는데 음수는 안 남음: 0의 존재와 무관
		sum += plus;
	else if (minus && !plus) {  // 음수는 남는데 양수는 안 남음
		if (!zero) sum += minus;  // 0이 안남으면 음수 더하고 0이 남으면 0이 더해짐
	}
	else if (minus && plus) {
		if (zero) sum += plus;  // 0이 있다면, 음수는 0과 곱해서 없애고 양수만 남긴다
		else sum += (minus + plus > minus * plus ? minus + plus : minus * plus);  // 0도 없으면 가능한 것 중 큰 것을 선택 
	}
	cout << sum;
}
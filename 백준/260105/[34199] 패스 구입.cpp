#include <iostream>
using namespace std;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	long long d, p1, p2, t1, t2, shortterm = 0;
	long long e1, e2;
	scanf("%lld %lld %lld %lld", &p1, &t1, &p2, &t2);
	e1 = p1 * t2, e2 = p2 * t1;  // 효율 비교
	if (e1 > e2) shortterm = 1;
	printf("? 1\n");
	fflush(stdout);

	scanf("%lld", &d);
	while (d != -1) {
		if (e1 > e2) {
			if ((shortterm + 1) * p1 <= p2) {  // 단기적으로 싼 패스를 사고
				printf("? 1\n");
				shortterm++;
			}
			else printf("? 2\n");  // 임계점에서 효율이 좋은 패스로 바꾼다
		}
		else {  // 1번 패스는 2번 패스보다 무조건 가격이 같거나 더 싸다
			printf("? 1\n");
		}
		fflush(stdout);
		scanf("%lld", &d);
	}
	printf("!\n");
	fflush(stdout);
}
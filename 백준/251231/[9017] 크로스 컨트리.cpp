#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(tuple<int, int, int> &t1, tuple<int, int, int> &t2) {
	if (get<1>(t1) == get<1>(t2)) return get<2>(t1) < get<2>(t2);
	return get<1>(t1) < get<1>(t2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, score = 1, team[201][2] = { 0, }, temp[1001] = { 0, };
		vector<tuple<int, int, int>> final;  // 순서대로 팀 번호, 팀 점수, 5번째 주자 점수
		vector<int> allowed;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> temp[j];
			team[temp[j]][0]++;
		}
		// 실격 안당한 팀 정리
		for (int j = 1; j <= 200; j++) {
			if (team[j][0] == 6) {
				allowed.push_back(j);
				final.push_back(make_tuple(j, 0, 0));
			}
		}

		for (int j = 1; j <= n; j++) {
			int idx = find(allowed.begin(), allowed.end(), temp[j]) - allowed.begin();
			if (idx == allowed.size())  // 주자 인정 안됨
				continue;
			if (team[idx][1] < 4)  // 팀별 상위 4명의 주자의 점수가 반영
				get<1>(final[idx]) += score++;
			else if (team[idx][1] == 4)  // 동점 비교용 5번째 주자 점수 기록
				get<2>(final[idx]) = score++;
			else score++;  // 6번째 주자는 기록은 안하지만 점수 변동은 필요
			team[idx][1]++;  // 팀별로 몇 번째 주자까지 세었는지 확인
		}
		sort(final.begin(), final.end(), compare);

		cout << get<0>(final[0]) << "\n";
	}
}
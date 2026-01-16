#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, k;
	string w;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<vector<int>> al;  // al[j]의 첫 번째 원소는 알파벳 개수, 이후는 위치
		vector<int> temp(1);
		for (int j = 0; j < 26; j++)
			al.push_back(temp);
		bool flag = false;
		cin >> w >> k;
		// 각 알파벳의 개수
		for (int j = 0; j < w.size(); j++) {
			al[w[j] - 'a'][0]++;
			al[w[j] - 'a'].push_back(j);
		}

		// 어떤 문자를 정확하게 k개 포함하는 최소/최대 길이 문자열은
		// 양끝의 문자 간격이 최소/최대가 된다
		int minsub = w.size() + 1, maxsub = -1;  // 문자열 길이
		int min_st, min_end, max_st, max_end;  // 문자열 양끝 위치
		for (int j = 0; j < 26; j++) {
			if (al[j][0] < k) continue;
			for (int l = 1; l + k - 1 < al[j].size(); l++) {
				if (minsub > al[j][l + k - 1] - al[j][l]) {  // 최소 간격
					minsub = al[j][l + k - 1] - al[j][l];
					min_st = al[j][l]; min_end = al[j][l + k - 1];
				}
				if (maxsub < al[j][l + k - 1] - al[j][l]) {  // 최대 간격
					maxsub = al[j][l + k - 1] - al[j][l];
					max_st = al[j][l]; max_end = al[j][l + k - 1];
				}
			}
		}
		if (minsub == w.size() + 1 && maxsub == -1) {  // 어떤 문자도 k개 이상 존재하지 않음
			cout << -1 << "\n";
			continue;
		}
		cout << min_end - min_st + 1 << " " << max_end - max_st + 1 << "\n";
	}
}
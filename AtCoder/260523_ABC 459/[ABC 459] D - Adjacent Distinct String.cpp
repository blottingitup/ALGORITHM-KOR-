#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int num[300001];
//vector<int> num[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		bool yes = true;
		string s;
		cin >> s;

		int alph[26] = { 0, };
		for (int j = 0; j < s.length(); j++) {
			alph[s[j] - 'a']++;
			if (alph[s[j] - 'a'] > (s.length() + 1) / 2) {
				yes = false;
				break;
			}
		}

		if (!yes) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
			map<char, int> num;  // alphabet : number of each letter mapping
			for (int j = 0; j < 26; j++) {
				num['a' + j] = alph[j];
			}

			char last_used = 'a';
			for (int j = 0; j < s.length(); j++) {
				int max_val = 0;
				char max_key = ' ';
				for (int k = 0; k < 26; k++) {
					if (j && 'a' + k == last_used) continue;// no duplicates
					if (max_val < num['a' + k]) {
						max_val = num['a' + k];
						max_key = 'a' + k;
					}
				}
				cout << max_key;
				num[max_key]--;
				last_used = max_key;
			}
			cout << "\n";
		}
	}
}
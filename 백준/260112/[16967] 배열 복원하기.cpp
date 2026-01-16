#include <iostream>
#include <vector>
using namespace std;

int arr[601][601];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int h, w, x, y;
	vector<vector<int>> orig(1);
	cin >> h >> w >> x >> y;
	for (int i = 1; i <= h + x; i++) {
		vector<int> temp(1);
		for (int j = 1; j <= w + y; j++) {
			cin >> arr[i][j];
			temp.push_back(-1);
		}
		orig.push_back(temp);
	}

	for (int i = 1; i <= h + x; i++) {
		for (int j = 1; j <= w + y; j++) {
			if ((i <= x && j <= w) || (i <= h && j <= y)) orig[i][j] = arr[i][j];  // 좌상단: 원래 보존 영역
			else if ((i > x && j > w) || (i > h && j > y)) orig[i - x][j - y] = arr[i][j];  // 우하단: 나머지 보존 영역
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (orig[i][j] == -1) orig[i][j] = arr[i][j] - orig[i - x][j - y];  // 중복 영역
		}
	}

	// 출력
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++)
			cout << orig[i][j] << " ";
		cout << "\n";
	}
}
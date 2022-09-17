#include <iostream>
#include <vector>

using namespace std;

int n = 4;
int answer = 10000000;

vector<vector<int>> pathes;
vector<bool> used;
vector<int> way;

void rec(int idx, int len);

int main() {
	used = vector<bool>(n);
	way = vector<int>(n);
	pathes = vector<vector<int>>(n, vector<int>(n, 0));

	pathes[0][0] = 0;
	pathes[0][1] = 1;
	pathes[0][2] = 4;
	pathes[0][3] = 6;

	pathes[1][0] = 1;
	pathes[1][1] = 0;
	pathes[1][2] = 5;
	pathes[1][3] = 2;

	pathes[2][0] = 4;
	pathes[2][1] = 5;
	pathes[2][2] = 0;
	pathes[2][3] = 3;

	pathes[3][0] = 6;
	pathes[3][1] = 2;
	pathes[3][2] = 3;
	pathes[3][3] = 0;

	way[0] = 0;
	rec(1, 0);

	cout << answer;

	return 0;
}

void rec(int idx, int len) {
	if (len >= answer) return;

	if (idx == n) {
		answer = min(answer, len);
	}

	for (int i = 1; i < n; i++) {
		if (used[i]) continue;

		way[idx] = i;

		used[i] = true;
		rec(idx + 1, len + pathes[way[idx - 1]][i]);
		used[i] = false;
	}
}
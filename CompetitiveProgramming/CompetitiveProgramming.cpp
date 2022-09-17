#include <fstream>
#include "split.h"

int n;
int answer = 10000000;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int> bestway;

vector<vector<int>> pathes;
vector<bool> used;
vector<int> way;

void initialize();
void fill();
void copy_way();
void out();

void rec(int idx, int len);

int main() {
	initialize();

	rec(1, 0);

	out();

	pathes[0][0] = 3;
	pathes[0][1] = 435;

	return 0;
}

void out() {
	cout << "The shortest way: " << answer << '\n';
	
	cout << "The way: 0";

	for (int i = 1; i < n; i++) {
		cout << " -> " << bestway[i];
	}

	cout << " -> 0";
}

void initialize() {
	fill();
	bestway = vector<int>(n);
	used = vector<bool>(n);
	way = vector<int>(n);
	way[0] = 0;
}

void fill() {
	string line;
	getline(cin, line);

	vector<string> elements = split(line, " ");
	n = elements.size();

	pathes = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		pathes[0][i] = stoi(elements[i]);
	}

	for (int i = 1; getline(cin, line); i++) {
		elements = split(line, " ");

		for (int j = 0; j < n; j++) {
			pathes[i][j] = stoi(elements[j]);
		}
	}
}

void rec(int idx, int len) {
	if (len >= answer) return;

	if (idx == n) {
		answer = min(answer, len + pathes[0][way[idx - 1]]);
		copy_way();
	}

	for (int i = 1; i < n; i++) {
		if (used[i]) continue;

		way[idx] = i;

		used[i] = true;
		rec(idx + 1, len + pathes[way[idx - 1]][i]);
		used[i] = false;
	}
}

void copy_way() {
	for (int i = 0; i < n; i++) {
		bestway[i] = way[i];
	}
}
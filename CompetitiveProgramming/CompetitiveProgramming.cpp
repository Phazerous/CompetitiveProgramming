#include <fstream>
#include <vector>

/*
Вывести все последовательности чисел от 1 до n, в которых каждое число встречается ровно один раз.
*/

using namespace std;
int n;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int> buffer;
vector<bool> used;

void rec(int idx);
void out();

int main() {
	cin >> n;
	
	buffer = vector<int>(n);
	used = vector<bool>(n + 1, false);

	rec(0);

	return 0;
}

void rec(int idx) {
	if (idx == n) {
		out();
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (used[i]) {
			continue;
		}

		buffer[idx] = i;
		used[i] = true;
		rec(idx + 1);
		used[i] = false;
	}
}

void out() {
	for (int number : buffer) {
		cout << number;
	}

	cout << '\n';
}

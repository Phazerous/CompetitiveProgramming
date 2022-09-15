#include <fstream>
#include <vector>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
vector<int> buffer;

void rec(int idx, int sum, int last);
void show(int idx);

int main() {
	cin >> n;

	buffer = vector<int>(n);

	rec(0, 0, 0);
	
	return 0;
}

void rec(int idx, int sum, int last) {
	if (sum == n) {
		show(idx);
		return;
	}

	for (int i = last; i <= n - sum; i++) {
		if (i == 0)
			continue;

		buffer[idx] = i;
		rec(idx + 1, sum + i, i);
	}
}

void show(int idx) {
	cout << n << " = ";

	for (int i = 0; i < idx; i++) {
		cout << buffer[i];

		if (i == idx - 1)
			break;

		cout << " + ";
	}

	cout << "\n";
}

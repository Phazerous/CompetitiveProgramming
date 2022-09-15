#include <fstream>
#include <vector>

/*
Вывести все последовательности длины n, состоящие из чисел от
1 до m. Каждое число может встречаться в последовательности
несколько раз или не встречаться совсем.
*/

using namespace std;
int n, m;
vector<int> buffer;

ifstream cin("input.txt");
ofstream cout("output.txt");

void rec(int idx);
void out();

int main() {
	cin >> n >> m;
	
	buffer = vector<int>(n);

	rec(0);

	return 0;
}

void rec(int idx) {
	if (idx == n) {
		out();
		return;
	}

	for (int i = 1; i <= m; i++) {
		buffer[idx] = i;
		rec(idx + 1);
	}
}

void out() {
	for (int number : buffer) {
		cout << number;
	}

	cout << '\n';
}

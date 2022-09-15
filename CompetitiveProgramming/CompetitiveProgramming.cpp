#include <fstream>
#include <vector>

/*
Сгенерировать все возможные комбинации правильных скобок с количеством 2n
Правильные:
(1 + 1) + (1  + 1) -> ()()
((1 + 1) + ((1 + 1))) -> (()(()))
Неправильные:
)(
(()))
*/

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int n;
vector<char> buffer;

void out();

void rec(int idx, int bal);

int main() {
	cin >> n;

	buffer = vector<char>(n * 2);
	rec(0, 0);
	
	return 0;
}

void rec(int idx, int bal) {
	if (idx == n * 2) {
		if (bal == 0)
			out();

		return;
	}

	buffer[idx] = '(';
	rec(idx + 1, bal + 1);

	if (bal == 0)
		return;

	buffer[idx] = ')';
	rec(idx + 1, bal - 1);
}

void out() {
	for (char c : buffer) {
		cout << c;
	}

	cout << '\n';
}
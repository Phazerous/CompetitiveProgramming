#include <fstream>
#include <vector>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int> buffer;

int n;

void rec();
void out();
int calcSum();

int main() {
	cin >> n;

	rec();

	return 0;
}

int calcSum() {
	int sum = 0;

	for (int num : buffer) {
		sum += num;
	}

	return sum;
}

void rec() {
	int currSum = calcSum();

	if (currSum == n) {
		out();
		return;
	}

	for (int i = 1; i <= n - currSum; i++) {
		if (currSum == 0 || (i >= buffer[buffer.size() - 1] && currSum + i <= n)) {
			buffer.push_back(i);
			rec();
			buffer.pop_back();
		}
	}
}

void out() {
	for (int i = 0; i < buffer.size(); i++) {
		if (i == 0) {
			cout << n << " = ";
		}

		cout << buffer[i];

		if (i != buffer.size() - 1) {
			cout << " + ";
		}
	}

	cout << '\n';
}
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int out = 0;
	for (int i = 5; n/i >= 1; i *= 5) {
		out += n / i;
	}
	cout << out << endl;
}

// Author: Aaron He
// Created: 9 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	cout << 2 * n << '\n';
	if (n % 4 != 0) {
		cout << n % 4;
	}
	for (int i = 0; i < n/4; i++) {
		cout << 4;
	}
	cout << '\n';
}

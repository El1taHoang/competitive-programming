// Author: Aaron He
// Created: 9 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int t = n * (n + 1)/2 - 1;
	cout << t << '\n';
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i << ' ' << j << '\n';
		}
	}
}

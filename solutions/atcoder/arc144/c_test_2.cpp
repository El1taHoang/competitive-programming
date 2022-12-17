// Author: Aaron He
// Created: 9 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int t = n - 1;
	cout << t << '\n';
	for (int i = 2; i <= n; i++) {
		cout << i << ' ' << k << '\n';
	}
}

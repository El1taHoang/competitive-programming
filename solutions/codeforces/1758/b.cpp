// Author: Aaron He
// Created: 25 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n == 2) {
			cout << 1 << ' ' << 3 << '\n';
			continue;
		} else if (n % 2 == 0) {
			cout << 1 << ' ' << 2 << ' ' << 3 << ' ';
			n -= 3;
		}
		for (int i = 0; i < n; i++) {
			cout << 2 << ' ';
		}
		cout << '\n';
	}
}

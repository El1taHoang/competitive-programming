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
		if (n % 2 == 0) {
			for (int i = n/2; i >= 1; i--) {
				cout << n - i << ' ';
			}
			for (int i = 1; i <= n/2; i++) {
				cout << n + i << ' ';
			}
		} else {
			for (int i = n/2; i >= 1; i--) {
				cout << 4 * n - 2 * i - (i == n/2) << ' ';
			}
			cout << 4 * n << ' ';
			for (int i = 1; i <= n/2; i++) {
				cout << 4 * n + 2 * i + (i == n/2) << ' ';
			}
		}
		cout << '\n';
	}
}

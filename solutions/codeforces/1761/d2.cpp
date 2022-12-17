// Author: Aaron He
// Created: 20 November 2022 (Sunday)
#include <iostream>
#include <vector>
using namespace std;

int g(int x) {
	int count = 0;
	for (int bit = 0; bit < 32; bit++) {
		count += (x >> bit) & 1;
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int ans = 0;
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < (1 << n); j++) {
				ans += g(i) + g(j) - g(i + j) == k;
			}
		}
		cout << ans << '\n';
	}
}

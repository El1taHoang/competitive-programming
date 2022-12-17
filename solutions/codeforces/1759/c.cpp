// Author: Aaron He
// Created: 18 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int l, r, x, a, b;
		cin >> l >> r >> x >> a >> b;
		if (b < a) {
			swap(a, b);
		}
		if (a == b) {
			cout << 0 << '\n';
		} else if (b - a >= x) {
			cout << 1 << '\n';
		} else if (a - l >= x || r - b >= x) { // a -> l -> b or a -> r -> b
			cout << 2 << '\n';
		} else if (r - a >= x && b - l >= x) { // a -> r -> l -> b
			cout << 3 << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}

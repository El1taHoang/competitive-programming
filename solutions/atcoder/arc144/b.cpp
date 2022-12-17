// Author: Aaron He
// Created: 9 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 1, r = 1e9;
	while (l < r) {
		int m = (l + r + 1)/2;
		long long op = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] > m) {
				op += (a[i] - m)/y;
			} else {
				op -= (m - a[i] + x - 1)/x;
			}
		}
		if (op >= 0) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	cout << l << '\n';
}

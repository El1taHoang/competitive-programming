// Author: Aaron He
// Created: 25 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int largest_factor = -1;
		vector<int> a(n + 1, 0);
		if (n % x != 0) {
			cout << -1 << '\n';
			continue;
		}
		int m = n/x;
		int cur = x;
		for (int i = 2; i * i <= m; i++) {
			while (m % i == 0) {
				a[cur] = cur * i;
				cur *= i;
				m /= i;
			}
		}
		if (m != 1) {
			a[cur] = cur * m;
		}
		a[1] = x;
		a[n] = 1;
		if (x == 1) {
			for (int i = 1; i <= n; i++) {
				a[i] = i;
			}
		} else if (x == n) {
			for (int i = 2; i < n; i++) {
				a[i] = i;
			}
		}
		for (int i = 2; i < n; i++) {
			if (!a[i])
				a[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " \n"[i == n];
		}
	}
}

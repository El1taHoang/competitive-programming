// Author: Aaron He
// Created: 9 December 2022 (Friday)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

void solve(int n, int k, vector<int> &a) {
	if (n <= 2 * k) {
		for (int i = 0; i < n; i++) {
			a[i] = (i + k) % n;
		}
		return;
	}
	if ((n - 1) % (2 * k) >= k) { // *
		debug(n, k, 1);
		solve(n - 1, k, a);
		int tmp = a[n - 1 - 2 * k];
		a[n - 1 - 2 * k] = a[n - 1 - k];
		a[n - 1 - k] = n - 1;
		a[n - 1] = tmp;
	} else {
		debug(n, k, 2);
		int rem = n % (2 * k);
		for (int i = n - 1; i >= n - k; i--) {
			a[i] = a[i - rem];
		}
		int j = n - 1;
		for (int i = n - 1 - k - rem; i < n - k; i++) {
			a[i] = j++;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	if (k > n/2) {
		cout << -1 << '\n';
		return 0;
	}
	set<int> s;
	vector<int> a(n);
	solve(n, k, a);
	for (int i = 0; i < n; i++) {
		cout << a[i] + 1 << ' ';
	}
	cout << '\n';
}

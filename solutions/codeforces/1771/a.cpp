// Author: Aaron He
// Created: 11 December 2022 (Sunday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int start = 0;
		int end = 0;
		for (int i = 0; i < n; i++) {
			start += a[i] == a[0];
			end += a[i] == a[n - 1];
		}
		if (a[0] == a[n - 1]) {
			cout << 1LL * n * (n - 1) << '\n';
		} else {
			cout << 1LL * 2 * start * end << '\n';
		}
	}
}

// Author: Aaron He
// Created: 21 November 2022 (Monday)
#include <algorithm>
#include <climits>
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
		int n, d;
		long long c;
		cin >> n >> c >> d;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		for (int i = n; i < d; i++) {
			a.push_back(0);
		}
		vector<long long> prefix(a.size() + 1);
		for (int i = 0; i < a.size(); i++) {
			prefix[i + 1] = prefix[i] + a[i];
		}
		if (1ll * a[0] * d < c) {
			cout << "Impossible" << '\n';
			continue;
		}
		if (prefix[min(n, d)] >= c) {
			cout << "Infinity" << '\n';
			continue;
		}
		debug(a);
		int l = 0, r = a.size() - 1;
		while (l < r) {
			int m = (l + r + 1)/2;
			long long best = d/(m + 1) * prefix[m + 1] + prefix[d % (m + 1)];
			if (best >= c) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		cout << l << '\n';
	}
}

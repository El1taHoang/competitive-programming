// Author: Aaron He
// Created: 18 November 2022 (Friday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Correction: I started problem A 39 minutes into contest start, not 55
	int t;
	cin >> t;
	while (t--) {
		int m, s;
		cin >> m >> s;
		vector<int> b(m);
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int mx = *max_element(b.begin(), b.end());
		int cur = mx * (mx + 1)/2 - accumulate(b.begin(), b.end(), 0);
		while (cur < s) {
			mx++;
			cur += mx;
		}
		cout << (cur == s ? "YES" : "NO") << '\n';
	}
}

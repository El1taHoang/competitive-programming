// Author: Aaron He
// Created: 10 December 2022 (Saturday)
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

int solve(int i, int l, int r, int p, vector<int> &a) {
	if (r - l <= 1) {
		return 0;
	}
	if (i < 0) {
		return 0;
	}
	int p2 = 1 << i;
	int m = lower_bound(a.begin(), a.end(), p + p2) - a.begin();
	int ans_l = solve(i - 1, l, m, p, a);
	int ans_r = solve(i - 1, m, r, p + p2, a);
	if (i < 3) {
		int extra = ((m == l || m == r) ? 0 : p2);
		debug(i, l, r, p, m);
		debug(ans_l, ans_r, extra);
	}
	if (m == l) {
		return ans_r;
	} else if (m == r) {
		return ans_l;
	}
	return p2 + min(ans_l, ans_r);
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << solve(29, 0, n, 0, a) << '\n';
}

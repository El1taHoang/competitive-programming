// Author: Aaron He
// Created: 11 December 2022 (Sunday)
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
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> rightmost(n, -1);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			if (y > rightmost[x] && y < x) {
				rightmost[x] = y;
			}
			if (x > rightmost[y] && x < y) {
				rightmost[y] = x;
			}
		}
		long long ans = 0;
		int cur = -1;
		for (int i = 0; i < n; i++) {
			cur = max(cur, rightmost[i]);
			debug(cur, i);
			ans += i - cur;
		}
		cout << ans << '\n';
	}
}

// Author: Aaron He
// Created: 30 October 2022 (Sunday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	int r, c;
	cin >> r >> c;
	int n;
	cin >> n;
	map<int, set<int>> walls_r, walls_c;
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		if (walls_r[r].empty()) {
			walls_r[r].insert(INT_MIN);
			walls_r[r].insert(INT_MAX);
		}
		if (walls_c[c].empty()) {
			walls_c[c].insert(INT_MIN);
			walls_c[c].insert(INT_MAX);
		}
		walls_r[r].insert(c);
		walls_c[c].insert(r);
	}
	int t;
	cin >> t;
	debug(r, c);
	while (t--) {
		char d;
		int l;
		cin >> d >> l;
		if ((d == 'L' || d == 'R') && walls_r[r].empty()) {
			c += l * (2 * (d == 'R') - 1);
		} else if ((d == 'U' || d == 'D') && walls_c[c].empty()) {
			r += l * (2 * (d == 'D') - 1);
		} else {
			if (d == 'L') {
				int new_c = *prev(walls_r[r].lower_bound(c));
				c = max(new_c + 1, c - l);
			}
			if (d == 'R') {
				int new_c = *walls_r[r].lower_bound(c);
				c = min(new_c - 1, c + l);
			}
			if (d == 'U') {
				int new_r = *prev(walls_c[c].lower_bound(r));
				r = max(new_r + 1, r - l);
			}
			if (d == 'D') {
				debug(walls_c[c]);
				int new_r = *walls_c[c].lower_bound(r);
				r = min(new_r - 1, r + l);
			}
		}
		debug(r, c);
		r = max(r, 1);
		c = max(c, 1);
		r = min(r, h);
		c = min(c, w);
		cout << r << ' ' << c << '\n';
	}
}

// Author: Aaron He
// Created: 4 November 2022 (Friday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <cassert>
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> p1(n + 1);
	vector<int> p2(n + 1);
	vector<pair<int, int>> p3_0(n + 1);
	vector<pair<int, int>> p3_1(n + 1);
	for (int i = 0; i < n; i++) {
		p1[i + 1] = p1[i] + a[i];
		p2[i + 1] = p2[i] ^ a[i];
	}
	for (int i = 0; i <= n; i += 2) {
		p3_0[i] = make_pair(p2[i], i);
	}
	for (int i = 1; i <= n; i += 2) {
		p3_1[i] = make_pair(p2[i], i);
	}
	sort(p3_0.begin(), p3_0.end());
	sort(p3_1.begin(), p3_1.end());
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		if (p2[l] != p2[r]) {
			cout << -1 << '\n';
			continue;
		}
		if (p1[l] == p1[r]) {
			cout << 0 << '\n';
			continue;
		}
		if ((r - l) % 2 != 0) {
			cout << 1 << '\n';
			continue;
		}
		if (l % 2 == 1) {
			auto it = lower_bound(p3_0.begin(), p3_0.end(), make_pair(p2[l], l + 1));
			if (it == p3_0.end()) {
				cout << -1 << '\n';
				continue;
			}
			pair<int, int> mid = *it;
			if (mid.second < r && mid.first == p2[l]) {
				if (a[l] == 0 || a[r - 1] == 0) {
					cout << 1 << '\n';
					continue;
				}
				cout << 2 << '\n';
				continue;
			}
			cout << -1 << '\n';
			continue;
		} else {
			debug(p3_1, p2[l]);
			auto it = lower_bound(p3_1.begin(), p3_1.end(), make_pair(p2[l], l + 1));
			if (it == p3_1.end()) {
				debug("yes");
				cout << -1 << '\n';
				continue;
			}
			pair<int, int> mid = *it;
			if (mid.second < r && mid.first == p2[l]) {
				if (a[l] == 0 || a[r - 1] == 0) {
					cout << 1 << '\n';
					continue;
				}
				cout << 2 << '\n';
				continue;
			}
			cout << -1 << '\n';
			continue;
		}
	}
}

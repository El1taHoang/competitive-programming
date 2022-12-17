// Author: Aaron He
// Created: 4 November 2022 (Friday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <algorithm>
#include <climits>
#include <cassert>
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
	vector<long long> p(n + 1);
	vector<int> p_xor(n + 1);
	vector<pair<int, int>> p_xor_with_i(n + 1);
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + a[i];
		p_xor[i + 1] = p_xor[i] ^ a[i];
	}
	for (int i = 0; i <= n; i++) {
		p_xor_with_i[i] = {p_xor[i], i};
	}
	sort(p_xor_with_i.begin(), p_xor_with_i.end());
	auto sum_range = [p] (int l, int r) {
		return p[r] - p[l];
	};
	auto xor_range = [p_xor] (int l, int r) {
		return p_xor[r] ^ p_xor[l];
	};
	debug(p_xor_with_i);
	while (q--) {
		int l, r;
		cin >> l >> r;
		debug(l, r);
		l--;
		//debug(l, r, xor_range(l, r), sum_range(l, r));
		if (xor_range(l, r) != 0) {
			cout << -1 << '\n';
			continue;
		}
		if (sum_range(l, r) == 0) {
			cout << 0 << '\n';
			continue;
		}
		if ((r - l) % 2 == 1) {
			cout << 1 << '\n';
			continue;
		}
		auto it = upper_bound(p_xor_with_i.begin(), p_xor_with_i.end(), make_pair(p_xor[l], l));
		if (it == p_xor_with_i.end()) {
			cout << -1 << '\n';
			continue;
		}
		pair<int, int> mid = *it;
		debug(mid);
		if (mid.first != p_xor[l] || mid.second >= r) {
			assert(mid.second == r);
			cout << -1 << '\n';
			continue;
		}
		if (a[l] == 0 || a[r - 1] == 0) {
			cout << 1 << '\n';
			continue;
		}
		cout << 2 << '\n';
	}
}

// Author: Aaron He
// Created: 18 November 2022 (Friday)
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

int mod(int a, int b) {
	return (a % b + b) % b;
}

int solve(vector<int> a, int p, int d0) {
		if (!a.size()) {
			return p - 1;
		}
		sort(a.begin(), a.end());
		a.resize(unique(a.begin(), a.end()) - a.begin());
		int save = 0;
		// no rollover
		int cur = mod(d0 - 1, p);
		int j = lower_bound(a.begin(), a.end(), cur) - a.begin();
		int new_j = mod(j, a.size());
		while (save < a.size()) {
			if (a[new_j] == cur && a[new_j] != d0) {
				save++;
			} else {
				break;
			}
			cur = mod(cur - 1, p);
			new_j = mod(new_j - 1, a.size());
		}
		return p - 1 - save;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		int d0;
		vector<int> a(n - 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> a[i];
		}
		cin >> d0;
		int ans = solve(a, p, d0);
		vector<int> b = a;
		if (b.size()) {
			b[(int)a.size() - 1]++;
		} else {
			b.push_back(1);
		}
		for (int i = (int)b.size() - 1; i >= 0; i--) {
			if (b[i] == p) {
				b[i] = 0;
				if (i) {
					b[i - 1]++;
				} else {
					a.push_back(1);
				}
			}
		}
		for (int i = 0; i < b.size(); i++) {
			a.push_back(b[i]);
		}
	  ans = min(ans, max(solve(a, p, d0), p - d0));
		cout << ans << '\n';
	}
}

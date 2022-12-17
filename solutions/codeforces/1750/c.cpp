// Author: Aaron He
// Created: 7 November 2022 (Monday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string a, b;
		cin >> n >> a >> b;
		// The boolean a[i] = b[i] gets flipped each operation. So a = b or a[i] != b[i] for all i
		bool all_different = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				all_different = false;
			}
		}
		if (!all_different && a != b) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		vector<pair<int, int>> ans;
		int prev = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] != a[i - 1]) {
				debug(i);
				if (a[i - 1] == '1') {
					ans.emplace_back(prev, i - 1);
				}
				prev = i;
			}
		}
		if (a[n - 1] == '1')
			ans.emplace_back(prev, n - 1);
		if (ans.size() % 2 && a == b || ans.size() % 2 == 0 && all_different) {
			ans.emplace_back(0, 0);
			ans.emplace_back(1, n - 1);
			ans.emplace_back(0, n - 1);
		}
		cout << ans.size() << '\n';
		for (pair<int, int> p : ans) {
			cout << p.first + 1 << ' ' << p.second + 1 << '\n';
		}
	}
}

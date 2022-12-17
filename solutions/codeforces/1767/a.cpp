// Author: Aaron He
// Created: 16 December 2022 (Friday)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bool ans1 = true, ans2 = true;
		vector<pair<int, int>> p(3);
		for (int i = 0; i < 3; i++) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end());
		for (int i = 1; i < 3; i++) {
			if (p[i].first == p[i - 1].first) {
				ans1 = false;
			}
		}
		for (int i = 0; i < 3; i++) {
			swap(p[i].first, p[i].second);
		}
		sort(p.begin(), p.end());
		for (int i = 1; i < 3; i++) {
			if (p[i].first == p[i - 1].first) {
				ans2 = false;
			}
		}
		bool ans = ans1 || ans2;
		cout << (ans ? "YES" : "NO") << '\n';
	}
}

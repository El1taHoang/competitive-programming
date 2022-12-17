// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<long long, long long>> a(n);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a[i] = {x, i};
		}
		sort(a.begin(), a.end());
		long long p = 1;
		vector<pair<long long, long long>> op;
		for (int i = 1; i < n; i++) {
			while (a[0].first * p < a[i].first) {
				p *= 2;
			}
			op.emplace_back(a[0].first * p - a[i].first, a[i].second);
		}
		cout << op.size() << '\n';
		for (auto &[x, i] : op) {
			cout << i + 1 << ' ' << x << '\n';
		}
	}
}

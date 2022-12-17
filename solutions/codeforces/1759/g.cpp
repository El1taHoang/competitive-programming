// Author: Aaron He
// Created: 25 November 2022 (Friday)
#include <set>
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
		cin >> n;
		int m = n/2;
		vector<int> a(m);
		vector<bool> used(n);
		vector<int> idx(n);
		bool good = true;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			a[i]--;
			idx[a[i]] = i;
			if (used[a[i]]) {
				good = false;
			}
			used[a[i]] = true;
		}
		set<int> available;
		vector<int> b(m, -1);
		for (int i = n - 1; i >= 0; i--) {
			if (used[i]) {
				available.insert(idx[i]);
			} else {
				if (available.empty()) {
					good = false;
					break;
				}
				b[*prev(available.end())] = i;
				available.erase(prev(available.end()));
			}
		}
		if (!good) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 0; i < m; i++) {
			cout << b[i] + 1 << ' ' << a[i] + 1 << ' ';
		}
		cout << '\n';
	}
}

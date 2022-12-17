// Author: Aaron He
// Created: 21 November 2022 (Monday)
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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool found_dec = false, found_inc = false;
		bool ans = true;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1]) {
				found_dec = true;
				ans = ans && !found_inc;
			} else if (a[i] > a[i - 1]) {
				found_inc = true;
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}

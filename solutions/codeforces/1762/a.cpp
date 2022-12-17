// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (accumulate(a.begin(), a.end(), 0) % 2 == 0) {
			ans = 0;
		}
		for (int i = 0; i < n; i++) {
			int cur = 0;
			if (a[i] % 2) {
				while (a[i] % 2) {
					a[i] /= 2;
					cur++;
				}
				ans = min(ans, cur);
			} else {
				while (a[i] % 2 == 0) {
					a[i] /= 2;
					cur++;
				}
				ans = min(ans, cur);
			}
		}
		cout << ans << '\n';
	}
}

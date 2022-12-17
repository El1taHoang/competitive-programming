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
		int n;
		cin >> n;
		n--;
		long long ans;
		cin >> ans;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			ans += max(0LL, (a[i] - ans + 1)/2);
		}
		cout << ans << '\n';
	}
}

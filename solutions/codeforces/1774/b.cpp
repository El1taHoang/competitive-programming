// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(m);
		int bigger_by_one = 0;
		bool ans = true;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			if (a[i] > n/k) {
				if (a[i] == n/k + 1) {
					bigger_by_one++;
				} else {
					ans = false;
				}
			}
		}
		cout << (ans && bigger_by_one <= n % k ? "YES" : "NO") << '\n';
	}
}

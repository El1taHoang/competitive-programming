// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<int> count(n);
		int ones = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				ones += a[i][j];
				count[i] += a[i][j];
			}
		}
		if (ones % n != 0) {
			cout << -1 << '\n';
			continue;
		}
		int need = ones/n;
		int i = 0; // advance i to next row with an excessive # of 1s
		int j = 0; // advance j to next row with a deficient # of 1s
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += abs(count[i] - need);
		}
		ans /= 2;
		cout << ans << '\n';
		while (true) {
			while (i < n && count[i] <= need) {
				i++;
			}
			while (j < n && count[j] >= need) {
				j++;
			}
			if (i >= n) {
				assert(j >= n);
				break;
			}
			for (int k = 0; k < m; k++) {
				if (count[i] == need || count[j] == need) {
					break;
				}
				if (a[i][k] == 1 && a[j][k] == 0) {
					cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
					swap(a[i][k], a[j][k]);
					count[i]--;
					count[j]++;
				}
			}
		}
	}
}

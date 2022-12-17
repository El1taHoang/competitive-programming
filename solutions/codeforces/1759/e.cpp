// Author: Aaron He
// Created: 18 November 2022 (Friday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, h;
		cin >> n >> h;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		int ans = 0;
		for (int j = 0; j < 3; j++) {
			long long cur_h = h;
			int state = 0;
			int cur_ans = 0;
			for (int i = 0; i < n; i++) {
				while (a[i] >= cur_h && state < 3) {
					if (state == j) {
						cur_h *= 3;
					} else {
						cur_h *= 2;
					}
					state++;
				}
				if (a[i] < cur_h) {
					cur_ans++;
					cur_h += a[i]/2;
				}
			}
			ans = max(ans, cur_ans);
		}
		cout << ans << '\n';
	}
}

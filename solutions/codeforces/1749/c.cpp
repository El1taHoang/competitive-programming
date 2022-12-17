#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test = 1; test <= n; test++) {
		int n;
		cin >> n;
		vector<long long> a(n);
		int ones = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			asser
			ones += a[i] == 1;
		}
		sort(a.begin(), a.end());
		int ans;
		for (int k = ones; k >= 0; k--) {
			int j = k;
			bool good = true;
			for (int i = 2; i <= k; i++) {
				if (j < n && a[j] <= i) {
					j++;
				} else {
					good = false;
				}
			}
			if (good) {
				ans = k;
				break;
			}
		}
		cout << ans << '\n';
	}
}


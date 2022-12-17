#include <iostream>
#include <vector>
#include <algorithm>
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
		int mx = -2e9;
		int mn = 2e9;
		int ans = -2e9;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			mx = max(a[i], mx);
			mn = min(a[i], mn);
			ans = max(ans, a[i] - a[(i + 1) % n]);
		}
		ans = max(ans, mx - a[0]);
		ans = max(ans, a[n - 1] - mn);
		cout << ans << '\n';
	}
}


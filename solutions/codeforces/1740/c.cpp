#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
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
	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long ans = 0;
		// start with largest element
		for (int i = 0; i < n - 2; i++) {
			ans = max(ans, (a[n - 1] - a[i]) + (a[i + 1] - a[i]));
		}
		// start with smallest element
		for (int i = n - 1; i >= 1; i--) {
			ans = max(ans, (a[i] - a[0]) + (a[i] - a[i - 1]));
		}
		cout << ans << '\n';
	}
}


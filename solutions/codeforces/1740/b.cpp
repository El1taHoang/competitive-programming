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
		vector<int> a(n);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			int b;
			cin >> b;
			ans += 2ll * b;
			ans += 2ll * a[i];
			a[i] = max(a[i], b);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n - 1; i++) {
			ans -= 2 * a[i];
		}
		cout << ans << '\n';
	}
}


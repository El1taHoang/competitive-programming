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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int g = a[0];
		for (int i = 0; i < n; i++) {
			g = __gcd(g, a[i]);
		}
		int ans = n;
		if (g == 1) {
			ans = 0;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (__gcd(i + 1, g) == 1) {
				ans = min(ans, n - i);
				break;
			}
		}
		ans = min(ans, 3);
		cout << ans << '\n';
	}
}


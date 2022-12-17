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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b(n + 1);
		b[0] = a[0];
		b[n] = a[n - 1];
		for (int i = 1; i < n; i++) {
			b[i] = (a[i] * a[i - 1])/__gcd(a[i], a[i - 1]);
		}
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != __gcd(b[i], b[i + 1])) {
				ans = false;
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}


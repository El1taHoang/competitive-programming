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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		bool ans = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i] || (b[i] - b[(i + 1) % n] > 1 && a[i] != b[i])) {
				ans = false;
				break;
			}
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}


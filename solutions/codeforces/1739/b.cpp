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
		vector<int> d(n), a(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		a[0] = d[0];
		bool multiple = false;
		for (int i = 1; i < n; i++) {
			int x1 = -d[i] + a[i - 1];
			int x2 = d[i] + a[i - 1];
			if (x1 < 0 || x1 == x2) {
				a[i] = x2;
			} else if (x2 < 0) {
				a[i] = x1;
			} else {
				multiple = true;
			}
		}
		if (multiple) {
			cout << -1 << '\n';
		} else {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " \n"[i == n - 1];
			}
		}
	}
}


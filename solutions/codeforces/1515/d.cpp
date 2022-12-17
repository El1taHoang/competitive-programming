#include <cassert>
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
		int n, a, b;
		cin >> n >> a >> b;
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			int c;
			cin >> c;
			c--;
			if (i < a) {
				l[c]++;
			}	else {
				r[c]++;
			}
		}
		int ans = abs(a - b)/2, swap = abs(a - b)/2;
		int extra = 0;
		//cout << ans << '\n';
		for (int i = 0; i < n; i++) {
			while (l[i] - 1 >= r[i] + 1 && a > b && swap > 0) {
				l[i]--;
				r[i]++;
				swap--;
			}
			while (l[i] + 1 <= r[i] - 1 && a < b && swap > 0) {
				l[i]++;
				r[i]--;
				swap--;
			}
			extra += abs(l[i] - r[i]);
		}
		//for (int i = 0; i < n; i++) {
		//	cout << l[i] << ' ';
		//}
		//cout << '\n';
		//for (int i = 0; i < n; i++) {
		//	cout << r[i] << ' ';
		//}
		//cout << '\n';
		//cout << extra << '\n';
		ans += extra/2;
		cout << ans << '\n';
	}
}


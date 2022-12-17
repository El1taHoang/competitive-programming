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
		int ans1 = 0;
		int ans2 = 1;
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			ans1 += a[i] != b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++) {
			ans2 += a[i] != b[i];
		}
		cout << min(ans1, ans2) << '\n';
	}
}


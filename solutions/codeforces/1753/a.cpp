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
		if (n % 2) {
			cout << -1 << '\n';
			continue;
		}
		vector<pair<int, int>> ans;
		for (int i = 1; i < n; i += 2) {
			if (a[i] == a[i - 1]) {
				ans.emplace_back(i, i + 1);
			}
			else {
				ans.emplace_back(i, i);
				ans.emplace_back(i + 1, i + 1);
			}
		}
		cout << ans.size() << '\n';
		for (pair<int, int> x : ans) {
			cout << x.first << ' ' << x.second << '\n';
		}
	}
}


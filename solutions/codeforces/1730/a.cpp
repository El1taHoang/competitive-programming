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
		int n, c;
		cin >> n >> c;
		vector<int> a(n);
		vector<int> count(101);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			count[a[i]]++;
		}
		int ans = 0;
		for (int i = 0; i <= 100; i++) {
			ans += min(count[i], c);
		}
		cout << ans << '\n';
	}
}


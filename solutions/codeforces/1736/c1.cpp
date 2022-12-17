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
		long long ans = 0;
		int cur_len = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] >= cur_len) {
				ans += cur_len;
				cur_len++;
			} else {
				ans += a[i];
				cur_len = a[i] + 1;
			}
		}
		cout << ans << '\n';
	}
}


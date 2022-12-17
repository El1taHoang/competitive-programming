#include <climits>
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		vector<long long> prefix_sum(n + 1);
		vector<int> prefix_xor(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			prefix_sum[i + 1] = prefix_sum[i] + a[i];
			prefix_xor[i + 1] = prefix_xor[i] ^ a[i];
		}
		auto xor_range = [=, prefix_xor] (int l, int r) {
			return prefix_xor[r + 1] ^ prefix_xor[l];
		};
		auto sum_range = [=, prefix_sum] (int l, int r) {
			return prefix_sum[r + 1] - prefix_sum[l];
		};
		vector<int> next_nonzero(n, n);
		vector<int> last_nonzero(n, -1);
		for (int i = 0; i < n; i++) {
			if (a[i] != 0) {
				if (i)
					next_nonzero[i - 1] = i;
				if (i < n - 1)
					last_nonzero[i + 1] = i;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			next_nonzero[i] = min(next_nonzero[i], next_nonzero[i + 1]);
		}
		for (int i = 1; i < n; i++) {
			last_nonzero[i] = max(last_nonzero[i], last_nonzero[i - 1]);
		}
		while (q--) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			int x = xor_range(l, r);
			pair<int, int> ans = {l, r};
			while (true) { // this will happen at most (log(max(a[i])) times
				int lb = l, rb = r;
				while (lb < rb) {
					int m = (lb + rb)/2;
					if (sum_range(l, m) - xor_range(l, m) == sum_range(l, r) - xor_range(l, r)) {
						rb = m;
					} else {
						lb = m + 1;
					}
				}
				if (rb - l < ans.second - ans.first) {
					ans = {l, rb};
				}
				if ((a[l] & x) == a[l] && l < r) {
					x ^= a[l];
					l = min(r, next_nonzero[l]);
				} else {
					break;
				}
			}
			cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';
		}
	}
}

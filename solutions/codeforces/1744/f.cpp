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
		int n;
		cin >> n;
		vector<int> p(n);
		vector<int> inv_p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
			inv_p[p[i]] = i;
		}
		vector<pair<int, int>> range(n); // range[i] = the smallest range that contains [0, 1, ..., i]
		range[0] = {inv_p[0], inv_p[0]};
		for (int i = 1; i < n; i++) {
			range[i] = {min(inv_p[i], range[i - 1].first), max(inv_p[i], range[i - 1].second)};
		}
		long long ans = 0;
		for (int len = 1; len <= n; len++) {
			int include = (len - 1)/2;
			pair<int, int> r = range[include];
			int left = r.first;
			int right = n - 1 - r.second;
			int extra = len - (r.second - r.first + 1);
			if (extra < 0) continue; 
			int ways = min(left, extra) - max(0, extra - right) + 1;
			debug(len, include, extra, left, right, ways);
			ans += ways;
		}
		cout << ans << '\n';
	}
}


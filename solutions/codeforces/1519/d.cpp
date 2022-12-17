#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, LLONG_MIN));
	vector<long long> p(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		p[i + 1] = p[i] + 1LL * a[i] * b[i];
	}
	for (int len = 0; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			if (len == 0 || len == 1) {
				dp[i][i + len] = 0;
			} else {
				dp[i][i + len] = dp[i + 1][i + len - 1] + 1LL * a[i + len - 1] * b[i] + 1LL * a[i] * b[i + len - 1] - 1LL * a[i] * b[i] - 1LL * a[i + len - 1] * b[i + len - 1];
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans + p[n] << '\n';
}



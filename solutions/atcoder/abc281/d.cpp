// Author: Aaron He
// Created: 10 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long INF = 1e18;
	vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(k + 1, vector<long long>(d, -INF)));
	dp[0][0][0] = 0;
	long long ans = -INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < d; l++) {
				dp[i + 1][j + 1][(l + a[i]) % d] = max(dp[i + 1][j + 1][(l + a[i]) % d], dp[i][j][l] + a[i]);
				dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
			}
		}
	}
	debug(dp, a);
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][k][0]);
	}
	cout << (ans < 0 ? -1 : ans) << '\n';
}

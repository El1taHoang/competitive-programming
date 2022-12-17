// Author: Aaron He
// Created: 12 December 2022 (Monday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

vector<int> decode(int mask) {
	int ones = (mask >> 4) & 3;
	int twos = (mask >> 2) & 3;
	int threes = (mask >> 0) & 3;
	return {threes, twos, ones};
}

int encode(vector<int> &v) {
	int mask = 0;
	for (int i = 0; i < 3; i++) {
		mask += v[i] << (2 * i);
	}
	return mask;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v = {1,2,0};
	debug(decode(encode(v)));
	vector<vector<long long>> dp(n + 1, vector<long long>(64));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 0; j < 64; j++) {
			vector<int> order = decode(j);
			for (int k = 0; k < 3; k++) {
				if ((x & order[k]) || (order[k] == 0)) {
					order[k] = x;
				}
			}
			dp[i + 1][encode(order)] += dp[i][j];
		}
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 64; j++) {
			ans += 1LL * dp[i][j] * (n - i);
		}
	}
	cout << ans << '\n';
}

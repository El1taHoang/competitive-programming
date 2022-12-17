// Author: Aaron He
// Created: 7 November 2022 (Monday)
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
		string s;
		cin >> n >> s;
		int block_len = 1;
		long long ans = 1;
		int ones = 0, zeroes = 0;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				block_len++;
			} else {
				block_len = 1;
			}
			ans = max(ans, 1ll * block_len * block_len);
		}
		for (int i = 0; i < n; i++) {
			zeroes += s[i] == '0';
			ones += s[i] == '1';
		}
		ans = max(ans, 1ll * ones * zeroes);
		cout << ans << '\n';
	}
}

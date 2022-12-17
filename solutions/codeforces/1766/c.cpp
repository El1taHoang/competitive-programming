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

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		// dp[i][j] = whether we can visit column i leaving from the top/bottom indicated by j
		vector<string> grid(2);
		for (int i = 0; i < 2; i++) {
			cin >> grid[i];
		}
		int start = 0;
		while (start < m && grid[0][start] == grid[1][start] && grid[0][start] == 'B') {
			start++;
		}
		int end = m;
		while (end > start && grid[0][end - 1] == grid[1][end - 1] && grid[0][end - 1] == 'B') {
			end--;
		}
		vector<vector<bool>> dp(m + 1, vector<bool>(2));
		dp[start][0] = dp[start][1] = true;
		for (int i = start + 1; i <= end; i++) {
			if (grid[0][i - 1] == grid[1][i - 1] && grid[0][i - 1] == 'B') {
				dp[i][0] = dp[i][0] || dp[i - 1][1];
				dp[i][1] = dp[i][1] || dp[i - 1][0];
			} else if (grid[0][i - 1] == 'B') {
				dp[i][0] = dp[i][0] || dp[i - 1][0];
			} else if (grid[1][i - 1] == 'B') {
				dp[i][1] = dp[i][1] || dp[i - 1][1];
			}
		}
		debug(dp);
		cout << ((dp[end][0] || dp[end][1]) ? "YES" : "NO") << '\n';
	}
}

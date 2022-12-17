// Author: Aaron He
// Created: 11 December 2022 (Sunday)
#include <queue>
#include <algorithm>
#include <climits>
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
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<vector<int>> adj(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<vector<int>> dp(n, vector<int>(n));
		vector<vector<int>> next(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}
		queue<pair<int, int>> q;
		vector<vector<bool>> vis(n, vector<bool>(n));
		for (int i = 0; i < n; i++) {
			vis[i][i] = true;
			q.emplace(i, i);
		}
		int ans = 1;
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();
			int source = p.first;
			int dest = p.second;
			vis[source][dest] = true;
			for (int v : adj[dest]) {
				if (!vis[source][v]) {
					q.emplace(source, v);
				} else {
					continue;
				}
				if (source != dest) {
					next[source][v] = next[source][dest];
					dp[source][v] = max(dp[source][v], dp[next[source][dest]][dest] + 2 * (s[source] == s[v]));
					dp[source][v] = max(dp[source][v], dp[source][dest]);
					dp[source][v] = max(dp[source][v], dp[next[source][dest]][v]);
					dp[v][source] = dp[source][v];
				} else {
					next[source][v] = v;
					dp[source][v] = max(dp[source][v], 2 * (s[source] == s[v]));
					dp[source][v] = max(dp[source][v], 1);
					dp[v][source] = dp[source][v];
				}
				ans = max(ans, dp[source][v]);
			}
		}
		debug(next, dp);
		cout << ans << '\n';
	}
}

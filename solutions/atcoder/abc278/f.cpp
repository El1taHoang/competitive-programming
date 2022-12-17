// Author: Aaron He
// Created: 30 November 2022 (Wednesday)
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 16;
int dp[MAX_N][1 << MAX_N];
vector<vector<int>> adj;
bool dfs(int u, int vis, bool first) {
	if (dp[u][vis] != -1) {
		return dp[u][vis] ^ first;
	}
	if ((vis >> u) & 1) {
		return false;
	}
	vis += 1 << u;
	bool win = true;
	for (int v : adj[u]) {
		if (dfs(v, vis, !first)) {
			win = false;
		}
	}
	vis -= 1 << u;
	dp[u][vis] = win ^ first;
	return win;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	memset(dp, -1, sizeof(int) * MAX_N * (1 << MAX_N));
	vector<string> s(n);
	adj = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (s[i].back() == s[j][0]) {
					adj[i].push_back(j);
				}
			}
		}
	}
	bool win = false;
	for (int i = 0; i < n; i++) {
		int vis = 0;
		win = win || dfs(i, vis, true);
	}
	cout << (win ? "First" : "Second") << '\n';
}

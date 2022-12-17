// Author: Aaron He
// Created: 12 November 2022 (Saturday)
#include <queue>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, bool>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		bool a;
		cin >> a;
		adj[u].emplace_back(v, a);
		adj[v].emplace_back(u, a);
	}
	vector<bool> has_switch(n);
	for (int i = 0; i < k; i++) {
		int s;
		cin >> s;
		s--;
		has_switch[s] = true;
	}
	vector<vector<int>> dist(n, vector<int>(2, INT_MAX)); // dist[i][j] = min moves to visit node i with j as the a-values you can walk on
	dist[0][1] = 0;
	queue<pair<int, bool>> q;
	q.emplace(0, true);
	while (!q.empty()) {
		int u = q.front().first;
		bool a = q.front().second;
		q.pop();
		for (auto &[v, a2] : adj[u]) {
			if ((a == a2 || has_switch[u]) && dist[v][a2] == INT_MAX) {
				dist[v][a2] = dist[u][a] + 1;
				q.emplace(v, a2);
			}
		}
	}
	int ans = min(dist[n - 1][0], dist[n - 1][1]);
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <iostream>
#include <vector>
using namespace std;

pair<int, int> dfs(int u, vector<vector<int>>& adj) {
	int res = 0;
	int res2 = 0;
	if (!adj[u].size()) res = 1;
	for (int v : adj[u]) {
		pair<int, int> next = dfs(v, adj);
		res += max(next.first, next.second);
		res2 = max(res2, next.second);
	}
	res2++;
	debug(res, res2);
	return {res, res2};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int j;
		cin >> j;
		j--;
		adj[j].push_back(i);
	}
	pair<int, int> ans = dfs(0, adj);
	cout << max(ans.first, ans.second) << '\n';
}


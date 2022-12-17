#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int a, vector<vector<int>>& adj, vector<int>& depth) {
	for (int b : adj[a]) {
		depth[b] = depth[a] + 1;
		dfs(b, adj, depth);
	}
}

int cost(int a, int max_depth, vector<vector<int>>& adj, vector<int> &depth, int before = 0) {
	int c = depth[a] > max_depth && (depth[a] - 1) % max_depth == 0;
	for (int b : adj[a]) {
		c += cost(b, max_depth, adj, depth, a);
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> depth(n);
		vector<vector<int>> adj(n);
		for (int i = 1; i <= n - 1; i++) {
			int j;
			cin >> j;
			j--;
			adj[j].push_back(i);
		}
		dfs(0, adj, depth);
		int l = 1, r = n;
		while (l < r) {
			int m = (l + r)/2;
			if (cost(0, m, adj, depth) <= k) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		cout << l << '\n';
	}
}


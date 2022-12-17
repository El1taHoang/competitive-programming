#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, anc);
	while (m--) {
		int q;
		cin >> q;
		if (q == 1) {
			int v;
			cin >> v;
			int ans = 0;
			for (int d = 0; d <= 20; d++) {
				for (int j = d; j <= 20; j++) {
					ans += val[anc[v][d]][j];
				}
			}
		}
	}
}


// Author: Aaron He
// Created: 20 November 2022 (Sunday)
#include <iostream>
#include <vector>
using namespace std;

vector<int> union_vector(vector<int> &a, vector<int> &b) {
	int i = 0;
	int j = 0;
	vector<int> res;
	while (true) {
		while (j < b.size() && i < a.size() && a[i] == b[j]) {
			j++;
		}
		if (j >= b.size() && i >= a.size()) {
			break;
		}
		if (i == a.size()) {
			res.push_back(b[j]);
			j++;
		} else if (j == b.size()) {
			res.push_back(a[i]);
			i++;
		} else if (a[i] < b[j]) {
			res.push_back(a[i]);
			i++;
		} else {
			res.push_back(b[j]);
			j++;
		}
	}
	return res;
}

vector<vector<int>> sets;
int cur;

void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj) {
	vector<int> res;
	vis[u] = true;
	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs(v, vis, adj);
		}
	}
	cur++;
	sets[u] = {cur};
	for (int v : adj[u]) {
		sets[u] = union_vector(sets[u], sets[v]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> b(n);
		vector<vector<int>> adj(n);
		vector<bool> source(n, true);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			for (int j = 0; j < n; j++) {
				if (b[i][j] == '1') {
					adj[j].push_back(i);
					source[i] = false;
				}
			}
		}
		sets = vector<vector<int>>(n);
		cur = 0;
		vector<bool> vis(n);
		for (int i = 0; i < n; i++) {
			if (source[i]) {
				int cur = 0;
				dfs(i, vis, adj);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << sets[i].size();
			for (int j = 0; j < sets[i].size(); j++) {
				cout << ' ' << sets[i][j];
			}
			cout << '\n';
		}
	}
}

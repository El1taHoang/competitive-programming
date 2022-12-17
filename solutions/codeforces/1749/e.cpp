#include <deque>
#include <queue>
#include <climits>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		vector<vector<bool>> bad(n, vector<bool>(m));
		for (int i = 0; i < n; i++) {
			cin >> grid[i];
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '#') {
					int di[4] = {-1, 1, 0, 0};
					int dj[4] = {0, 0, -1, 1};
					for (int d = 0; d < 4; d++) {
						int ni = i + di[d];
						int nj = j + dj[d];
						if (ni < n && ni >= 0 && nj < m && nj >= 0) {
							bad[ni][nj] = true;
						}
					}
				}
			}
		}
		vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
		vector<vector<pair<int, int>>> from(n, vector<pair<int, int>>(m, {-1, -1}));
		deque<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			if (!bad[i][0] && grid[i][0] == '#') {
				q.emplace_back(i, 0);
				dist[i][0] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			if (!bad[i][0] && grid[i][0] != '#') {
				q.emplace_back(i, 0);
				dist[i][0] = 1;
			}
		}
		while (!q.empty()) {
			pair<int, int> cell = q.front();
			q.pop_front();
			int i = cell.first;
			int j = cell.second;
			int di[4] = {-1, 1, -1, 1};
			int dj[4] = {-1, -1, 1, 1};
			for (int d = 0; d < 4; d++) {
				int ni = i + di[d];
				int nj = j + dj[d];
				if (ni < n && ni >= 0 && nj < m && nj >= 0) {
					if (!bad[ni][nj] && dist[ni][nj] == INT_MAX) {
						if (grid[ni][nj] == '#') {
							dist[ni][nj] = dist[i][j];
							q.emplace_front(ni, nj);
						} else {
							dist[ni][nj] = dist[i][j] + 1;
							q.emplace_back(ni, nj);
						}
						from[ni][nj] = {i, j};
					}
				}
			}
		}
		int min_dist = INT_MAX;
		pair<int, int> cur;
		for (int i = 0; i < n; i++) {
			if (dist[i][m - 1] < min_dist) {
				min_dist = dist[i][m - 1];
				cur = {i, m - 1};
			}
		}
		if (min_dist == INT_MAX) {
			cout << "NO" << '\n';
			continue;
		} else {
			cout << "YES" << '\n';
		}
		while (cur.second != 0) {
			grid[cur.first][cur.second] = '#';
			cur = from[cur.first][cur.second];
		}
		grid[cur.first][cur.second] = '#';
		for (int i = 0; i < n; i++) {
			cout << grid[i] << '\n';
		}
	}
}


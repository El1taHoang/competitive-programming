// Author: Aaron He
// Created: 10 November 2022 (Thursday)
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int sqrt(int n) {
	int i;
	for (i = 0; i * i < n; i++);
	return i * i == n ? i : -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> dirs;
	// i^2 + j^2 = m
	for (int i = 0; i * i <= m; i++) {
		int j = sqrt(m - i * i);
		if (j == -1) continue;
		dirs.emplace_back(i, j);
		if (i != 0) {
			dirs.emplace_back(-i, j);
		}
		if (j != 0) {
			dirs.emplace_back(i, -j);
		}
		if (i != 0 && j != 0) {
			dirs.emplace_back(-i, -j);
		}
	}
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	dist[0][0] = 0;
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int i = cur.first, j = cur.second;
		for (pair<int, int> dir : dirs) {
			int ni = i + dir.first, nj = j + dir.second;
			if (ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] == INT_MAX) {
				dist[ni][nj] = dist[i][j] + 1;
				q.emplace(ni, nj);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (dist[i][j] == INT_MAX ? -1 : dist[i][j]) << " \n"[j == n - 1];
		}
	}
}

// Author: Aaron He
// Created: 30 November 2022 (Wednesday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

struct rect {
	int r1 = INT_MAX, c1 = INT_MAX, r2 = INT_MIN, c2 = INT_MIN;
	bool inside_of(int r, int c, int h, int w) {
		return r <= r1 && c <= c1 && r2 < r + h && c2 < c + w;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long x = 123;
	int H, W, n;
	cin >> H >> W >> n;
	int h, w;
	cin >> h >> w;
	vector<vector<int>> grid(H, vector<int>(W));
	vector<rect> range(n + 1);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> grid[i][j];
			int x = grid[i][j];
			range[x].r1 = min(range[x].r1, i);
			range[x].c1 = min(range[x].c1, j);
			range[x].r2 = max(range[x].r2, i);
			range[x].c2 = max(range[x].c2, j);
		}
	}
	for (int i = 0; i <= H - h; i++) {
		for (int j = 0; j <= W - w; j++) {
			int distinct = 0;
			for (int val = 1; val <= n; val++) {
				if (!range[val].inside_of(i, j, h, w)) {
					distinct++;
				}
			}
			cout << distinct << ' ';
		}
		cout << '\n';
	}
}

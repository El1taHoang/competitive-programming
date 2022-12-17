// Author: Aaron He
// Created: 16 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> a[i][j];
		}
	}
	vector<pair<int, int>> b;
	for (int i = 0; i < n; i++) {
		bool found = false;
		for (int j = i; j < n; j++) {
			if (a[i][j] == 1) {
				found = true;
				if (b.empty()) {
					b.emplace_back(i, j);
				} else {
					pair<int, int> last = b.back();
					if (i <= last.second) {
						b[(int)b.size() - 1].second = max(last.second, j);
					} else {
						b.emplace_back(i, j);
					}
				}
			}
		}
		if (!found) {
			b.emplace_back(i, i);
		}
	}
	debug(b);
}

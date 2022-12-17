// Author: Aaron He
// Created: 10 November 2022 (Thursday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	// 0 <= a[i] + k * i <= n
	// -a[i] <= k * i <= n - a[i]
	// -a[i]/i <= k <= (n - a[i])/i
	vector<vector<int>> mex(m + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = max(1, -a[i]/i - 1); j <= min(m, (n - a[i])/i + 1); j++) {
			mex[j].push_back(a[i] + j * i);
		}
	}
	for (int i = 1; i <= m; i++) {
		sort(mex[i].begin(), mex[i].end());
		bool found = false;
		int k = 0;
		for (int j = 0; j < mex[i].size(); j++) {
			if (mex[i][j] == k) {
				k++;
			}
		}
		cout << k << '\n';
	}
}

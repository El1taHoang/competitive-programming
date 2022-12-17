// Author: Aaron He
// Created: 12 November 2022 (Saturday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		a.push_back(a[i]);
	}
	int j = 0;
	long long remove;
	long long ans = LLONG_MAX;
	debug(a);
	for (int i = 0; i < 2 * n; i++) {
		if (j <= i) {
			j = i + 1;
			remove = a[i];
		}
		while (j < 2 * n && j + 1 - i <= n && (a[j] == a[j - 1] || a[j] == (a[j - 1] + 1) % m)) {
			remove += a[j];
			j++;
		}
		ans = min(ans, sum - remove);
		remove -= a[i];
	}
	cout << ans << '\n';
}

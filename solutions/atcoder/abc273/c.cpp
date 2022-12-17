// Author: Aaron He
// Created: 30 October 2022 (Sunday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> distinct(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> ans(n);
	for (int i = n - 2; i >= 0; i--) {
		distinct[i] = distinct[i + 1] + (a[i] != a[i + 1]);
	}
	for (int i = n - 1; i >= 0; i--) {
		ans[distinct[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
}

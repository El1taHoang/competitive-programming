// Author: Aaron He
// Created: 26 November 2022 (Saturday)
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
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> suffix(n);
	for (int i = 0; i < n; i++) {
		suffix[i] = i;
	}
	for (int i = m - 1; i >= 1; i--) {
		swap(suffix[a[i]], suffix[a[i] + 1]);
	}
	int j = 0;
	for (int i = 0; i < m; i++) {
		debug(j, suffix);
		cout << suffix[j] + 1 << '\n';
		if (i < m - 1) {
			swap(suffix[a[i + 1]], suffix[a[i + 1] + 1]);
		}
		if (a[i] == j) {
			j++;
		} else if (a[i] == j - 1) {
			j--;
		}
	}
}

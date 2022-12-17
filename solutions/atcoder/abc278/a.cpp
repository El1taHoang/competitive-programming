// Author: Aaron He
// Created: 30 November 2022 (Wednesday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	k = min(k, n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i >= k) {
			cout << a[i] << ' ';
		}
	}
	for (int i = 0; i < k; i++) {
		cout << 0 << ' ';
	}
	cout << '\n';
}

// Author: Aaron He
// Created: 20 November 2022 (Sunday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		bool ans = true;
		if (a + b >= n) {
			ans = a == n && b == n;
		} else {
			ans = n - a - b >= 2;
		}
		cout << (ans ? "Yes" : "No") << '\n';
	}
}

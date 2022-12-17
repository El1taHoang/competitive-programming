// Author: Aaron He
// Created: 21 November 2022 (Monday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << a + b + c - max({a, b, c}) - min({a, b, c}) << '\n';
	}
}

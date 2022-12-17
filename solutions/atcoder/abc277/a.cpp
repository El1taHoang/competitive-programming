// Author: Aaron He
// Created: 12 November 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == x) {
			cout << i + 1 << '\n';
			break;
		}
	}
}

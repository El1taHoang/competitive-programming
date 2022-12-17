// Author: Aaron He
// Created: 4 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (n + 1)/2 << '\n';
		int i = 2;
		int j = 3 * n;
		for (int k = 0; k < (n + 1)/2; k++) {
			cout << i << ' ' << j << '\n';
			i += 3;
			j -= 3;
		}
	}
}

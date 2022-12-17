// Author: Aaron He
// Created: 30 October 2022 (Sunday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long x;
	int k;
	cin >> x >> k;
	long long p10 = 1;
	for (int i = 0; i < k; i++) {
		p10 *= 10;
		long long x1 = x - x % p10;
		long long x2 = x1 + p10;
		if (x - x1 < x2 - x) {
			x = x1;
		} else {
			x = x2;
		}
	}
	cout << x << '\n';
}

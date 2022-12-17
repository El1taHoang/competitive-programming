// Author: Aaron He
// Created: 18 November 2022 (Friday)
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
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int k = 1;
		bool found = false;
		int cur = n;
		int p2 = 0, p5 = 0;
		while (cur % 5 == 0) {
			cur /= 5;
			p5++;
		}
		while (cur % 2 == 0) {
			cur /= 2;
			p2++;
		}
		cur = n;
		while (p2 < p5 && cur % 5 == 0 && 2 * k <= m) {
			found = true;
			k *= 2;
			cur /= 5;
			p2++;
		}
		while (p5 < p2 && cur % 2 == 0 && 5ll * k <= m) {
			found = true;
			k *= 5;
			cur /= 2;
			p5++;
		}
		while (10ll * k <= m) {
			found = true;
			k *= 10;
		}
		debug(cur, k);
		k = m - m % k;
		cout << 1ll * n * (found ? k : m) << '\n';
	}
}

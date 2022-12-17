// Author: Aaron He
// Created: 9 December 2022 (Friday)
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
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 1; i <= n; i++) {
			a[i - 1] = i;
		}
		while (true) {
			bool good = true;
			for (int i = 0; i < n; i++) {
				if (abs(i + 1 - a[i]) < k) {
					good = false;
				}
			}
			if (good) {
				debug(n, k, a);
				break;
			}
			if (!next_permutation(a.begin(), a.end())) {
				break;
			}
		}
	}
}

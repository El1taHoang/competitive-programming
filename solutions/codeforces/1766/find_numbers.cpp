// Author: Aaron He
// Created: 12 December 2022 (Monday)
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	vector<int> primes;
	int sqrt_mx = 3200;
	int mx = 1e7;
	vector<bool> is_prime(sqrt_mx + 1, true);
	int p = 0;
	for (int i = 2; i * i <= mx; i++) {
		if (is_prime[i]) {
			if (i > 2) {
				int p1 = primes.back() * i;
				if (p1 < mx) {
					p = p1;
				}
			}
			primes.push_back(i);
			for (int j = i * i; j <= sqrt_mx; j += i) {
				is_prime[j] = false;
			}
		}
	}
	cout << p << '\n';
}

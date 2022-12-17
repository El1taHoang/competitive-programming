// Author: Aaron He
// Created: 12 December 2022 (Monday)
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#include <cmath>
#include <cassert>
vector<bool> sieve;
vector<int> primes;
int int_sqrt(int n) {
	long long res = sqrt(n) + 1;
	while (res * res > n) {
		res--;
	}
	return res;
}
void generate_primes(int mx) {
	assert(!sieve.size());
	sieve.resize(mx + 1, true);
	for (int i = 0; i <= mx; i++) {
		if (i < 2) {
			sieve[i] = false;
		}
		if (sieve[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= mx; j += i) {
				sieve[j] = false;
			}
		}
	}
}
#include <iostream>
bool is_prime(int n) {
	if (n < sieve.size()) {
		return sieve[n];
	} else {
#ifdef DEBUG
		cerr << "Naive approach is taken since sieve is not big enough n=" << n << ", sieve.size()=" << sieve.size() << '\n';
#endif
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return n >= 2;
}

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int mx = 1e7;
	generate_primes(int_sqrt(mx));
	debug(primes.size(), primes.back());
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x + 1 == y) {
			cout << -1 << '\n';
			continue;
		}
		int d = y - x;
		int ans = INT_MAX;
		for (int p : primes) {
			if (p * p > d) {
				break;
			}
			if (d % p == 0) {
				int dx = ((-x) % p + p) % p;
				ans = min(ans, dx);
			}
			while (d % p == 0) {
				d /= p;
			}
		}
		if (d > 1) {
			int dx = ((-x) % d + d) % d;
			ans = min(ans, dx);
		}
		cout << ans << '\n';
	}
}

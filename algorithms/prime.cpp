/*
Author: Aaron He
Created: 12 December 2022
*/
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
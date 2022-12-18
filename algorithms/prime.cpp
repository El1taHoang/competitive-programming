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
			if (1LL * i * i > mx) {
				continue;
			}
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
// Theorem: each integer n >= 2 is prime or has a prime factor <= sqrt(n)
// Theorem 2: the second smallest factor of n >= 2 is prime
template <typename T>
vector<pair<T, int>> prime_factors(T n) {
	vector<pair<T, int>> res;
	int j = 0;
	for (int i = 2; 1LL * i * i <= n; i++) {
		if (j < primes.size() && i <= primes[j]) {
			i = primes[j];
			j++;
		}
		if (i * i > n) break;
		if (n % i == 0) {
			int count = 0;
			while (n % i == 0) {
				n /= i;
				count++;
			}
			res.emplace_back(i, count);
		}
	}
	if (n > 1) {
		res.emplace_back(n, 1);
	}
	return res;
}
template <typename T>
vector<T> unique_prime_factors(T n) {
	vector<pair<T, int>> factors = prime_factors(n);
	vector<T> res;
	for (auto &[p, e] : factors) {
		res.push_back(p);
	}
	return res;
}
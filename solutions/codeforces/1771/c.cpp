// Author: Aaron He
// Created: 11 December 2022 (Sunday)
#include <cassert>
#include <set>
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

const int mx = 1e9;
vector<int> primes;

bool has_pair() {
	int n;
	cin >> n;
	assert(n >= 2 && n <= 1e5);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		assert(a[i] >= 1 && a[i] <= 1e9);
	}
	for (int p : primes) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % p == 0) {
				cnt++;
			}
			while (a[i] % p == 0) {
				a[i] /= p;
				if (cnt >= 2) {
					return true;
				}
			}
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1] && a[i] > 1) {
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	int lim = 4e4;
	vector<bool> is_prime(lim + 1, true);
	for (int i = 2; i * i <= mx; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= lim; j += i) {
				is_prime[j] = false;
			}
		}
	}
	debug(primes.size());
	assert(t >= 1 && t <= 1e5);
	while (t--) {
		cout << (has_pair() ? "YES" : "NO") << '\n';
	}
}

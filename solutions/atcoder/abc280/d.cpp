// Author: Aaron He
// Created: 6 December 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	long long k;
	cin >> k;
	/* k = p0^e0 * p1^e1 * ... is equivalent to:
		- n! is big enough to have e_i copies of p_i for each i
	*/
	vector<pair<long long, int>> factor;
	for (int i = 2; 1LL * i * i <= k; i++) {
		int count = 0;
		while (k % i == 0) {
			count++;
			k /= i;
		}
		if (count) {
			// i is prime
			factor.emplace_back(i, count);
		}
	}
	if (k != 1) {
		// k is prime
		factor.emplace_back(k, 1);
	}
	long long n = 0;
	for (auto &[p, e] : factor) {
		int cur_exp = 0;
		long long cur_n = 0;
		while (cur_exp < e) {
			cur_n += p;
			long long temp = cur_n;
			while (temp % p == 0) {
				temp /= p;
				cur_exp++;
			}
		}
		n = max(n, cur_n);
	}
	cout << n << '\n';
}

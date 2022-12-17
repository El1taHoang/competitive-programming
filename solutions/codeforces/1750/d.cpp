// Author: Aaron He
// Created: 7 November 2022 (Monday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
//const int MOD = 1e9 + 7;
const int MOD = 998244353;
const int mxN = 0;

int add(int a, int b) {
	return ((1LL * a + b) % MOD + MOD) % MOD;
}

template <typename Head, typename... Tail>
int add(Head h, Tail... t) {
	return add(h, add(t...));
}

int sub(int a, int b) {
	return add(a, -b);
}

int mult(int a, int b) {
	return 1LL * a * b % MOD;
}

template <typename Head, typename... Tail>
int mult(Head h, Tail... t) {
	return mult(h, mult(t...));
}

int pow(int b, int p) {
	int res = 1;
	while (p) {
		if (p & 1) {
			res = mult(res, b);
		}
		p /= 2;
		b = mult(b, b);
	}
	return res;
}

int inv(int x) {
	return pow(x, MOD - 2);
}

int divide(int a, int b) {
	return mult(a, inv(b));
}

int fact_arr[mxN + 1] = {}, ifact_arr[mxN + 1] = {};

void init() {
	ifact_arr[0] = fact_arr[0] = 1;
	for (int i = 1; i <= mxN; i++) {
		ifact_arr[i] = mult(ifact_arr[i - 1], inv(i));
		fact_arr[i] = mult(fact_arr[i - 1], i);
	}
}

int fact(int n) {
	if (fact_arr[0] == 0) {
		init();
	}
	return fact_arr[n];
}

int ifact(int n) {
	if (ifact_arr[0] == 0) {
		init();
	}
	return ifact_arr[n];
}

int nck(int n, int k) {
	if (k > n) {
		return 0;
	}
	return mult(fact(n), mult(ifact(k), ifact(n - k)));
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// Count # of numbers such that gcd(a[i - 1], x) = a[i] and x <= m
		// Or gcd(a[i - 1]/a[i], x) = 1 and x <= m/a[i]
		// Use idea of totient function
		int ans = 1;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] % a[i] != 0) {
				ans = 0;
				break;
			}
			if (a[i - 1] == a[i]) {
				ans = mult(ans, m/a[i]);
				continue;
			}
			int total = m/a[i];
			int num = a[i - 1]/a[i];
			vector<int> f;
			for (int j = 2; j * j <= num; j++) {
				if (num % j == 0) {
					f.push_back(j);
				}
				while (num % j == 0) {
					num /= j;
				}
			}
			if (num > 1) {
				f.push_back(num);
			}
			debug(f);
			int rel_prime = 0;
			// Number of prime factors of n <= log(n)
			for (int mask = 1; mask < (1 << f.size()); mask++) {
				int sign = -1;
				int union_size = total;
				for (int j = 0; j < f.size(); j++) {
					if (mask & (1 << j)) {
						sign *= -1;
						union_size /= f[j];
					}
				}
				rel_prime += sign * union_size;
			}
			ans = mult(ans, sub(total, rel_prime));
		}
		cout << ans << '\n';
	}
}

// Author: Aaron He
// Created: 20 November 2022 (Sunday)
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int mxN = 3e6+1;

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
	if (p < 0) return 0;
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
	if (k < 0) return 0;
	if (k > n) {
		return 0;
	}
	return mult(fact(n), mult(ifact(k), ifact(n - k)));
}
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
	int n, k;
	cin >> n >> k;
	int ans = 0;
	if (k == 0) {
		cout << pow(3, n) << '\n';
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		int carry_blocks = nck(k - 1, i - 1);
		int case_1 = mult(pow(3, n - (i + (i - 1))), nck((n - k) - 1, (i - 1) - 1)); // 1
		int case_2 = mult(pow(3, n - (i + (i - 1))), nck((n - k) - 1, i - 1)); // 10
		int case_3 = mult(pow(3, n - (i + i)), nck((n - k) - 1, i - 1)); // 01
		int case_4 = mult(pow(3, n - (i + i)), nck((n - k) - 1, (i + 1) - 1)); // 010
		ans = add(ans, mult(carry_blocks, add(case_1, case_2, case_3, case_4)));
		debug(i, carry_blocks, case_1, ans);
	}
	cout << ans << '\n';
}

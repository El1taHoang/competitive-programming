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
		int n;
		cin >> n;
		vector<int> a(n);
		int ones = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ones += a[i] == 1;
		}
		vector<int> dp(ones + 1);
		for (int i = ones - 1; i >= 0; i--) {
			int p = divide(pow(ones - i, 2), divide(mult(n, n - 1), 2));
			debug(p);
			dp[i] = add(divide(1, p), dp[i + 1]);
		}
		int n1 = 0;
		for (int i = n - ones; i < n; i++) {
			n1 += (a[i] == 1);
		}
		debug(n1);
		cout << dp[n1] << '\n';
	}
}


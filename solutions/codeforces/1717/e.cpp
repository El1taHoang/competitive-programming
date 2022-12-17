#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
	return ((1LL * a + b) % MOD + MOD) % MOD;
}

int mult(int a, int b) {
	return 1LL * a * b % MOD;
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

const int mxN = 0;
int fact[mxN + 1], ifact[mxN + 1];

int nck(int n, int k) {
	if (k > n) {
		return 0;
	}
	return mult(fact[n], mult(ifact[k], ifact[n - k]));
}

void init() {
	fact[0] = ifact[0] = 1;
	for (int i = 1; i <= mxN; i++) {
		fact[i] = mult(fact[i - 1], i);
		ifact[i] = mult(ifact[i - 1], inv(i));
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int c = 1; c <= n - 2; c++) {
		int d = n - c;
		vector<int> factors;
		for (int i = 1; i * i <= d; i++) {
			if (d % i == 0) {
				factors.push_back(i);
				if (i * i != d) {
					factors.push_back(d/i);
				}
			}
		}
		sort(factors.begin(), factors.end(), greater<int>());
		map<int, int> count_map;
		for (int f : factors) {
			int count = (d - 1)/f;
			for (int f2 : factors) {
				if (f2 % f == 0) {
					count -= count_map[f2];
				}
			}
			count_map[f] = count;
			ans = add(ans, mult(count, mult(c/__gcd(c, f), f)));
		}
	}
	cout << ans << '\n';
}


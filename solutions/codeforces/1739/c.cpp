#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 998244353;

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

const int mxN = 60;
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
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> win(n + 1);
		vector<int> loss(n + 1);
		for (int i = 2; i <= n; i += 2) {
			win[i] = add(loss[i - 2], nck(i - 1, i/2 - 1));
			loss[i] = add(nck(i, i/2), -add(1, win[i]));
		}
		cout << win[n] << ' ' << loss[n] << ' ' << 1 << '\n';
	}
}


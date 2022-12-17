#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m;

int add(int a, int b) {
	return ((1LL * a + b) % m + m) % m;
}

int mult(int a, int b) {
	return 1LL * a * b % m;
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
	return pow(x, m - 2);
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
int f(vector<bool> v) {
	if (accumulate(v.begin(), v.end(), 0) == v.size()) {
		return 1;
	}
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!v[i]) {
			vector<bool> new_v = v;
			new_v[i] = 1;
			if (i > 1 && v[i - 2]) {
				new_v[i - 1] = 1;
			}
			if (i < v.size() - 2 && v[i + 2]) {
				new_v[i + 1] = 1;
			}
			ans += f(new_v);
		}
	}
	return ans;
}
int guess(int n) {
	vector<int> dp(n + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] += i * dp[i - 1] - (i - 2) * dp[i - 2];
	}
	return dp[n];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> m;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; i++) {
		cout << f(vector<bool>(i)) << '\n';
	}
	for (int i = 2; i <= n; i++) {
		// positition of ith turn on
		for (int p = 0; p < i; p++) {
			// position of i - 1 turn on
		}
	}
	//cout << guess(n);
}


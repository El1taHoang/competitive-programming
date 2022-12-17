// Author: Aaron He
// Created: 4 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = 6;
	int q = n * (n + 1)/2;
	int p_xor = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		if ((i + 1) % 4 == 0) {
			a[i] = p_xor;
		} else {
			a[i] = rand() % 10;
		}
		p_xor ^= a[i];
		a[i] = 1;
	}
	cout << n << ' ' << q << '\n';
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cout << i << ' ' << j << '\n';
		}
	}
}

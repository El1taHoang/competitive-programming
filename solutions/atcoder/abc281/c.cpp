// Author: Aaron He
// Created: 10 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	long long t;
	cin >> n >> t;
	vector<int> a(n);
	long long s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	long long prefix = 0;
	for (int i = 0; i < n; i++) {
		prefix += a[i];
		if (t - t % s + prefix > t) {
			cout << i + 1 << ' ' << t - (t - t % s + (prefix - a[i])) << '\n';
			break;
		}
	}
}

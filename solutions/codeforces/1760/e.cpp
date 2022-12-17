// Author: Aaron He
// Created: 21 November 2022 (Monday)
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
		int zeroes = 0, ones = 0;
		long long inversions = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i]) {
				ones++;
			} else {
				zeroes++;
				inversions += ones;
			}
		}
		int increase = 0;
		int zeroes_before = 0;
		int ones_before = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				increase = max(increase, ones_before - (zeroes - zeroes_before));
				ones_before++;
			} else {
				zeroes_before++;
				increase = max(increase, (zeroes - zeroes_before) - ones_before);
			}
		}
		cout << inversions + increase << '\n';
	}
}

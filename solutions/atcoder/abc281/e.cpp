// Author: Aaron He
// Created: 10 December 2022 (Saturday)
#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	multiset<int> small, big;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i < m) {
			small.insert(a[i]);
			sum += a[i];
		}
	}
	while (small.size() > k) {
		sum -= *prev(small.end());
		big.insert(*prev(small.end()));
		small.erase(prev(small.end()));
	}
	for (int i = 0; i <= n - m; i++) {
		cout << sum << ' ';
		if (i == n - m) break;
		if (small.find(a[i]) != small.end()) {
			sum -= a[i];
			small.erase(small.find(a[i]));
		} else {
			big.erase(big.find(a[i]));
		}
		if (small.empty() || a[i + m] < *prev(small.end())) {
			sum += a[i + m];
			small.insert(a[i + m]);
		} else {
			big.insert(a[i + m]);
		}
		while (small.size() < k) {
			sum += *big.begin();
			small.insert(*big.begin());
			big.erase(big.begin());
		}
		while (small.size() > k) {
			sum -= *prev(small.end());
			big.insert(*prev(small.end()));
			small.erase(prev(small.end()));
		}
	}
	cout << '\n';
}

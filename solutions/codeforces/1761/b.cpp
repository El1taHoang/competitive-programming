// Author: Aaron He
// Created: 20 November 2022 (Sunday)
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
		vector<int> count(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			count[a[i]]++;
		}
		int distinct = 0;
		for (int x : count) {
			if (x) {
				distinct++;
			}
		}
		cout << (distinct == 2 ? n/2 + 1 : n) << '\n';
	}
}

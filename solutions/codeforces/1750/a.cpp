// Author: Aaron He
// Created: 7 November 2022 (Monday)
#include <algorithm>
#include <climits>
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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << (a[0] == *min_element(a.begin(), a.end()) ? "Yes" : "No") << '\n';
	}
}

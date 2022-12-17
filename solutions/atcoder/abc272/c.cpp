// Author: Aaron He
// Created: 10 November 2022 (Thursday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> even, odd;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			even.push_back(x);
		} else {
			odd.push_back(x);
		}
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	int ans = -1;
	if (even.size() >= 2) {
		ans = max(ans, even[even.size() - 1] + even[even.size() - 2]);
	}
	if (odd.size() >= 2) {
		ans = max(ans, odd[odd.size() - 1] + odd[odd.size() - 2]);
	}
	cout << ans << '\n';
}

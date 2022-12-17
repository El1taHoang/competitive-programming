// Author: Aaron He
// Created: 21 November 2022 (Monday)
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
		int max1 = INT_MIN, max2 = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] >= max1) {
				max2 = max1;
				max1 = a[i];
			} else if (a[i] > max2) {
				max2 = a[i];
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] - (a[i] == max1 ? max2 : max1) << " \n"[i == n - 1];
		}
	}
}

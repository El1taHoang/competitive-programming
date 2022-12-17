// Author: Aaron He
// Created: 10 November 2022 (Thursday)
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << accumulate(a.begin(), a.end(), 0) << '\n';
}

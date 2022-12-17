// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		pair<int, int> range = {0, 1};
		for (int i = 0; i < n - 1; i++) {
			pair<int, int> new_range = {range.first, range.second + 1};
			if (s[i] == '0') {
				range.first = 0;
				range.second = new_range.second - 1;
			} else {
				range.first = new_range.first + 1;
				range.second = i + 1 + 1;
			}
			cout << range.second - range.first << " \n"[i == n - 2];
			debug(range);
		}
	}
}

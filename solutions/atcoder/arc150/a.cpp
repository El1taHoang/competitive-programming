// Author: Aaron He
// Created: 17 November 2022 (Thursday)
#include <algorithm>
#include <climits>
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
		int n, k;
		string s;
		cin >> n >> k >> s;
		int l = -1, r = -1;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				r = i;
				if (l == -1) {
					l = i;
				}
			}
		}
		if (r == -1) {
			vector<int> segments;
			int len = 0;
			for (int i = 0; i < n; i++) {
				if (i && s[i] != s[i - 1]) {
					if (len) {
						segments.push_back(len);
					}
					len = 0;
				}
				if (s[i] == '?') {
					len++;
				}
			}
			if (s[n - 1] == '?') {
				segments.push_back(len);
			}
			sort(segments.rbegin(), segments.rend());
			if ((segments.size() && segments[0] == k) && (segments.size() <= 1 || segments[1] != k)) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
			debug(segments);
			continue;
		}
		bool ans = true;
		if (r - l + 1 > k) {
			ans = false;
		}
		for (int i = l; i <= r; i++) {
			if (s[i] == '0') {
				ans = false;
			}
		}
		while (l > 0 && s[l - 1] == '?') {
			l--;
		}
		while (r < n - 1 && s[r + 1] == '?') {
			r++;
		}
		if (r - l + 1 < k) {
			ans = false;
		}
		if (r - l + 1 > k && s[l] == '?' && s[r] == '?') {
			ans = false;
		}
		cout << (ans ? "Yes" : "No") << '\n';
	}
}

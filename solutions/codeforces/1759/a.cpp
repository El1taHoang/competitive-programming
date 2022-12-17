// Author: Aaron He
// Created: 18 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// Started 55 min into contest
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string t = "Yes";
		int j = 0;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == s[0]) {
				j = i;
			}
		}
		bool ans = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[j]) {
				ans = false;
			}
			j = (j + 1) % t.size();
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}

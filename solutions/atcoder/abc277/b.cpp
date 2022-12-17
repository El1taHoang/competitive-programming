// Author: Aaron He
// Created: 12 November 2022 (Saturday)
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	bool ans = true;
	set<string> seen;
	while (t--) {
		string s;
		cin >> s;
		if (seen.find(s) != seen.end()) {
			ans = false;
		}
		seen.insert(s);
		bool suit_valid = false;
		bool value_valid = false;
		for (char suit : "HDCS") {
			suit_valid = suit_valid || suit == s[0];
		}
		for (char value : "A23456789TJQK") {
			value_valid = value_valid || value == s[1];
		}
		ans = ans && suit_valid && value_valid;
	}
	cout << (ans ? "Yes" : "No") << '\n';
}

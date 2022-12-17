// Author: Aaron He
// Created: 10 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	bool ans = s.size() == 8 && s[1] >= '1';
	for (int i = 0; i < s.size(); i++) {
		if (i > 0 && i < (int)s.size() - 1) {
			ans = ans && s[i] >= '0' && s[i] <= '9';
		} else {
			ans = ans && s[i] >= 'A' && s[i] <= 'Z';
		}
	}
	cout << (ans ? "Yes" : "No") << '\n';
}

// Author: Aaron He
// Created: 6 December 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	string t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i]) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << t.size() << '\n';
}

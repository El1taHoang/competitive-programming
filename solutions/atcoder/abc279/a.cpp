// Author: Aaron He
// Created: 26 November 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	int ans = 0;
	cin >> s;
	for (char c : s) {
		if (c == 'v') {
			ans++;
		} else {
			ans += 2;
		}
	}
	cout << ans << '\n';
}

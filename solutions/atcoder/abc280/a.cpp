// Author: Aaron He
// Created: 6 December 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	int ans = 0;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			ans += c == '#';
		}
	}
	cout << ans << '\n';
}

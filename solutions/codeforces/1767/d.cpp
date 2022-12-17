// Author: Aaron He
// Created: 16 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

pair<int, int> solve(int n, string &s) {
	if (n == 1) {
		int winner = s[n - 1] - '0' + 1;
		return {winner, winner};
	}
	pair<int, int> res = solve(n - 1, s);
	debug(res);
	if (s[n - 1] == '0') {
		return {2 * res.first - 1, 2 * res.second - 1};
	} else {
		return {2 * res.first - 1, 2 * res.second - 1};
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	pair<int, int> res = solve(n, s);
	for (int i = res.first; i <= res.second; i++) {
		cout << i << ' ';
	}
	cout << '\n';
}

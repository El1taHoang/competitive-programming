// Author: Aaron He
// Created: 25 November 2022 (Friday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << s;
		reverse(s.begin(), s.end());
		cout << s << '\n';
	}
}

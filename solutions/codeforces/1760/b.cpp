// Author: Aaron He
// Created: 21 November 2022 (Monday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		cout << *max_element(s.begin(), s.end()) - 'a' + 1 << '\n';
	}
}

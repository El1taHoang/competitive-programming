// Author: Aaron He
// Created: 6 December 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> s(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> s[i + 1];
	}
	for (int i = 0; i < n; i++) {
		cout << s[i + 1] - s[i] << ' ';
	}
	cout << '\n';
}

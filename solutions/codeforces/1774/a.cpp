// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string a;
		cin >> n >> a;
		int s = a[0] - '0';
		for (int i = 1; i < n; i++) {
			if (a[i] == '1') {
				if (s == 0) {
					cout << '+';
					s = 1;
				} else {
					cout << '-';
					s = 0;
				}
			} else {
				cout << '+';
			}
		}
		cout << '\n';
	}
}

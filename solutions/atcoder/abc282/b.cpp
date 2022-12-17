// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool good = true;
			for (int k = 0; k < m; k++) {
				if (s[i][k] != 'o' && s[j][k] != 'o') {
					good = false;
				}
			}
			ans += good;
		}
	}
	cout << ans << '\n';
}

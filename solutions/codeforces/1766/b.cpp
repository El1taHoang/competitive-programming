// Author: Aaron He
// Created: 12 December 2022 (Monday)
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
		vector<vector<int>> seen(26, vector<int>(26));
		bool ans = false;
		for (int i = 0; i < n - 1; i++) {
			int count = seen[s[i] - 'a'][s[i + 1] - 'a'];
			if (count >= 2 || count >= 1 && (!i || s[i] != s[i + 1] || s[i] != s[i - 1])) {
				cout << s[i] << ' ' << s[i + 1] <<  '\n';
				ans = true;
			}
			seen[s[i] - 'a'][s[i + 1] - 'a']++;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}
}

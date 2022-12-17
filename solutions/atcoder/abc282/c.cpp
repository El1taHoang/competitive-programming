// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	vector<bool> enclosed(n);
	int prev;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '"') {
			count++;
			if (count % 2 == 0) {
				for (int j = prev + 1; j < i; j++) {
					enclosed[j] = true;
				}
			}
			prev = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!enclosed[i] && s[i] == ',') {
			s[i] = '.';
		}
	}
	cout << s << '\n';
}

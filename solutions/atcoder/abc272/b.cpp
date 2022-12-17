// Author: Aaron He
// Created: 10 November 2022 (Thursday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> good(n, vector<bool>(n));
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> attendees(k);
		for (int j = 0; j < k; j++) {
			cin >> attendees[j];
			attendees[j]--;
		}
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < k; l++) {
				good[attendees[j]][attendees[l]] = true;
			}
		}
	}
	bool ans = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = ans && good[i][j];
		}
	}
	cout << (ans ? "Yes" : "No") << '\n';
}

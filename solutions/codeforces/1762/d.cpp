// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <set>
#include <iostream>
#include <vector>
using namespace std;
 
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif
 
int query(int a, int b) {
	cout << "? " << a + 1 << ' ' << b + 1 << endl;
	int res;
	cin >> res;
	return res;
}
 
void answer(int a, int b) {
	cout << "! " << a + 1 << ' ' << b + 1 << endl;
	int res;
	cin >> res;
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> s; // Candidates for zero
		for (int i = 0; i < n; i++) {
			s.insert(i);
		}
		for (int i = 0; i < n; i++) {
			if (s.find(i) == s.end()) continue;
			int last = -1;
			vector<pair<int, int>> results;
			set<int> gs;
			int mx = -1;
			for (int j : s) {
				if (i != j) {
					int res = query(i, j);
					mx = max(mx, res);
					results.emplace_back(j, res);
					if (gs.find(res) != gs.end()) {
						s.erase(i);
						debug(gs);
						break;
					}
					gs.insert(res);
					last = res;
				}
			}
			for (auto &[j, g] : results) {
				if (g != mx) {
					s.erase(j);
				}
			}
			if (s.size() <= 2) {
				answer(*s.begin(), *prev(s.end()));
				break;
			}
			debug(s);
		}
	}
}

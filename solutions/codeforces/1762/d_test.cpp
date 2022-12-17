// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <chrono>
#include <random>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
using namespace std;
 
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

bool good = true;
vector<int> a;
 
int query(int x, int y) {
	return __gcd(a[x], a[y]);
}
 
void answer(int x, int y) {
	if (a[x] != 0 && a[y] != 0) {
		debug("BAD", x, y, a);
		good = false;
	} else {
	}
}
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int n = 210; n < 230; n++) {
		a.resize(n);
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		for (int asdf = 0; asdf < 1000; asdf++) {
			shuffle(a.begin(), a.end(), rng);
			if (!good) return 0;
			set<int> s; // Candidates for zero
			for (int i = 0; i < n; i++) {
				s.insert(i);
			}
			int ops = 0;
			for (int i = 0; i < n; i++) {
				if (s.find(i) == s.end()) continue;
				int last = -1;
				vector<pair<int, int>> results;
				set<int> gs;
				int mx = -1;
				for (int j : s) {
					if (i != j) {
						ops++;
						if (ops > 2 * n) {
							good = false;
							debug("BAD", ops, a);
						}
						int res = query(i, j);
						mx = max(mx, res);
						//debug(i, j);
						results.emplace_back(j, res);
						if (gs.find(res) != gs.end()) {
							s.erase(i);
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
				//debug(s);
				if (s.size() <= 2) {
					answer(*s.begin(), *prev(s.end()));
					break;
				}
			}
			if (!next_permutation(a.begin(), a.end())) {
				break;
			}
		}
	}
}

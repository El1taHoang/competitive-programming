// Author: Aaron He
// Created: 1 December 2022 (Thursday)

// Based off editorial solution, both the official editorial and the user editorial
// Good resource for Grundy numbers (from user editorial):
// - https://codeforces.com/blog/entry/66040
#include <climits>
#include <set>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

void go_first() {
	cout << "First" << endl;
}

void go_second() {
	cout << "Second" << endl;
}

// I convert {index, length} pair to [left bound, right bound)
pair<int, int> get_move() {
	int a, b;
	cin >> a >> b;
	a--;
	return {a, a + b};
}

void make_move(int a, int b) {
	a++;
	cout << a << ' ' << b - a + 1 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	// Easy mirror strategy
	if (l != r) {
		int len = l + (n - l) % 2;
		go_first();
		make_move(n/2 - len/2, n/2 + (len - len/2));
		while (true) {
			auto [l, r] = get_move();
			if (l == -1) {
				break;
			}
			int gap = (n - len)/2 + len;
			if (l > n/2) {
				make_move(l - gap, r - gap);
			} else {
				make_move(l + gap, r + gap);
			}
		}
	} else { // O(n^2) grundy number strategy
		// From editorial: g_i is the grundy number if the game state consists of only a contiguous segment of size i
		vector<int> g(n + 1);
		g[0] = 0;
		for (int i = 1; i <= n; i++) {
			// Mex of all possible states. Suppose you start your next move at index j.
			// a_0, ..., a_{j - 1}, deleted, ..., deleted, a_{j + l}, ..., a_n
			// Now you have one segment of size j and one segment of size n - l - j
			// By the Sprague-Grundy theorem, take the mex over all (g_j xor g_{n - l - j})
			vector<bool> found(n);
			int mex = 0;
			for (int j = 0; j <= i - l; j++) {
				int xor_states = g[j] ^ g[i - l - j];
				if (xor_states < n) {
					found[xor_states] = true;
				}
			}
			while (found[mex] && mex < n) {
				mex++;
			}
			g[i] = mex;
		}
		debug(g);
		// Keep track of all contiguous segments
		set<pair<int, int>> s;
		s.emplace(0, n);
		bool computer_move = true;
		if (g[n] > 0) {
			go_first();
		} else {
			assert(g[n] == 0);
			go_second();
			computer_move = false;
		}
		auto record_move = [&s] (int l, int r) {
			auto it = prev(s.upper_bound(make_pair(l, INT_MAX)));
			pair<int, int> s1 = {it->first, l};
			pair<int, int> s2 = {r, it->second};
			s.erase(it);
			if (s1.first != s1.second) {
				s.insert(s1);
			}
			if (s2.first != s2.second) {
				s.insert(s2);
			}
		};
		while (true) {
			int l_move, r_move;
			if (computer_move) {
				// Consider moving in each segment
				// We want xor (new segments) = 0
				// Or equivalently: xor (two new segments we create) = xor (everything else)
				int total_xor = 0;
				for (auto &[ls, rs] : s) {
					total_xor ^= g[rs - ls];
				}
				assert(total_xor > 0); // We should be winning
				bool found = false;
				for (auto &[ls, rs] : s) { // This double for loop is actually O(n)
					for (int j = ls; j <= rs - l; j++) {
						if ((total_xor ^ g[rs - ls]) == (g[j - ls] ^ g[rs - j - l])) { // This is guaranteed to happen due to theory on nim games (see codeforces article)
							l_move = j;
							r_move = j + l;
							make_move(j, j + l);
							found = true;
							break;
						}
					}
					if (found) break;
				}
				assert(found);
			} else {
				pair<int, int> move = get_move();
				debug(move);
				l_move = move.first;
				r_move = move.second;
			}
			if (l_move == -1) break;
			debug(l_move, r_move);
			record_move(l_move, r_move);
			debug(computer_move);
			debug(s);
			computer_move = !computer_move;
		}
	}
}

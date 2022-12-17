// Author: Aaron He
// Created: 30 November 2022 (Wednesday)
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	map<pair<int, int>, bool> following;
	while (q--) {
		int query, a, b;
		cin >> query >> a >> b;
		pair<int, int> p1 = {a, b};
		pair<int, int> p2 = {b, a};
		switch (query) {
			case 1:
				following[p1] = true;
				break;
			case 2:
				following[p1] = false;
				break;
			case 3:
				cout << (following[p1] && following[p2] ? "Yes" : "No") << '\n';
				break;
		}
	}
}

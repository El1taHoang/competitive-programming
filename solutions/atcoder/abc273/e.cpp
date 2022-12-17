// Author: Aaron He
// Created: 30 October 2022 (Sunday)
#include <stack>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	vector<int> ans(q);
	vector<int> add(q, -1);
	map<int, int> save;
	vector<int> prev_add(q, -1);
	int prev = -1;
	stack<int> a;
	for (int i = 0; i < q; i++) {
		string s;
		cin >> s;
		prev_add[i] = prev;
		if (s == "ADD") {
			prev = i;
			cin >> add[i];
		} else if (s == "DELETE") {
			if (prev != -1) {
				prev = prev_add[prev];
			}
		} else if (s == "SAVE") {
			int j;
			cin >> j;
			save[j] = prev;
		} else if (s == "LOAD") {
			int j;
			cin >> j;
			if (save.find(j) != save.end()) {
				prev = save[j];
			} else {
				prev = -1;
			}
		}
		cout << (prev == -1 ? -1 : add[prev]) << " \n"[i == q - 1];
	}
}

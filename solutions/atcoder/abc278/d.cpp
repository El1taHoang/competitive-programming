// Author: Aaron He
// Created: 30 November 2022 (Wednesday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<int> step(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	int shared_value;
	int total_steps = 0;
	while (q--) {
		int query;
		cin >> query;
		if (query == 1) {
			cin >> shared_value;
			total_steps++;
		} else if (query == 2) {
			int i, x;
			cin >> i >> x;
			i--;
			if (step[i] < total_steps) {
				step[i] = total_steps;
				a[i] = shared_value;
			}
			a[i] += x;
		} else if (query == 3) {
			int i;
			cin >> i;
			i--;
			if (step[i] < total_steps) {
				cout << shared_value << '\n';
			} else {
				cout << a[i] << '\n';
			}
		}
	}
}

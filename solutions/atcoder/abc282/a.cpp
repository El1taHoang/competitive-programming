// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cout << char('A' + i);
	}
	cout << '\n';
}

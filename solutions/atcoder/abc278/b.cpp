// Author: Aaron He
// Created: 30 November 2022 (Wednesday)
#include <iostream>
#include <vector>
using namespace std;

bool is_confusing(int h, int m) {
	int new_h = h - h % 10 + m/10;
	int new_m = h % 10 * 10 + m % 10;
	return new_h < 24 && new_m < 60;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, m;
	cin >> h >> m;
	while (!is_confusing(h, m)) {
		m++;
		if (m % 60 == 0) {
			m = 0;
			h++;
			if (h % 24 == 0) {
				h = 0;
			}
		}
	}
	cout << h << ' ' << m << '\n';
}

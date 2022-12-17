#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool is_square(int n) {
	int l = 0, r = 4e4;
	while (l < r) {
		int m = (l + r)/2;
		if (m * m < n) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return l * l == n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool can;
		if (n == 1 || n == 3) {
			can = false;
		} else if (n % 2 == 0 && is_square(n/2) || n % 4 == 0 && is_square(n/4)) {
			can = true;
		} else {
			can = false;
		}
		cout << (can ? "YES" : "NO") << '\n';
	}
}


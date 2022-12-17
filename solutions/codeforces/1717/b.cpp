#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k, r, c;
		cin >> n >> k >> r >> c;
		r--, c--;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j + (k - r) + (k - c)) % k == 0) {
					cout << 'X';
				} else {
					cout << '.';
				}
			}
			cout << '\n';
		}
	}
}


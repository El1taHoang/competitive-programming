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
		int n, m;
		cin >> n >> m;
		if (m < n) {
			cout << "No\n";
			continue;
		}
		if (n % 2 == 0) {
			if (m % 2 == 0) {
				cout << "Yes\n";
				for (int i = 0; i < n - 2; i++) {
					cout << 1 << ' ';
				}
				cout << (m - (n - 2))/2 << ' ' << (m - (n - 2))/2 << '\n';
			} else {
				cout << "No\n";
			}
		} else {
			cout << "Yes\n";
			for (int i = 0; i < n - 1; i++) {
				cout << 1 << ' ';
			}
			cout << m - (n - 1) << '\n';
		}
	}
}


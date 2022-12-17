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
		long long r, b, d;
		cin >> r >> b >> d;
		if (r * (d + 1) < b || b * (d + 1) < r) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}


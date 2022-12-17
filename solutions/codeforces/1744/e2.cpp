#include <cassert>
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<int> fa, fb;
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				fa.push_back(i);
				fa.push_back(a/i);
			}
		}
		for (int i = 1; i * i <= b; i++) {
			if (b % i == 0) {
				fb.push_back(i);
				fb.push_back(b/i);
			}
		}
		vector<long long> fab;
		for (int i : fa) {
			for (int j : fb) {
				fab.push_back(1ll * i * j);
			}
		}
		long long x = -1, y = -1;
		for (long long f : fab) {
			long long f2 = 1ll * a * b/f;
			assert((1ll * a * b) % f == 0);
			if (a < c - c % f && b < d - d % f2) {
				x = c - c % f;
				y = d - d % f2;
				break;
			}
			if (a < c - c % f2 && b < d - d % f) {
				x = c - c % f2;
				y = d - d % f;
				break;
			}
		}
		if (x != -1 && y != -1) {
			assert(a < x && x <= c);
			assert(b < y && y <= d);
			assert((x * y) % (a * b) == 0);
		}
		cout << x << ' ' << y << '\n';
	}
}


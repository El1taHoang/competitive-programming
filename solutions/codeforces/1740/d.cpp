#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		vector<int> pos(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			a[i]--;
		}
		for (int i = 0; i < k; i++) {
			pos[a[i]] = i;
		}
		bool ans = true;
		int space = n * m - 4;
		debug(a, pos, space);
		for (int i = 0; i < k; i++) {
			if (pos[i] > (k - i - 1) + space) {
				debug(i);
				ans = false;
			}
		}
		cout << (ans ? "YA" : "TIDAK") << '\n';
	}
}


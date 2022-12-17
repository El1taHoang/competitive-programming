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
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> p2;
		int cur_p2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			while (a[i] % 2 == 0) {
				a[i] /= 2;
				cur_p2++;
			}
			int p2_i = 0;
			int j = i + 1;
			while (j % 2 == 0) {
				j /= 2;
				p2_i++;
			}
			p2.push_back(p2_i);
		}
		sort(p2.begin(), p2.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i < p2.size(); i++) {
			if (cur_p2 >= n) break;
			cur_p2 += p2[i];
			ans++;
		}
		if (cur_p2 < n) {
			ans = -1;
		}
		cout << ans << '\n';
	}
}


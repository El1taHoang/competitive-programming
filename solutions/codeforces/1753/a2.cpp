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
		int n;
		cin >> n;
		vector<int> a(n);
		int sum = 0;
		int can_1 = 0;
		int can_n1 = 0;
		int num_1 = 0;
		int num_n1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += abs(a[i]);
			if (i && a[i]) {
				can_1++;
				can_n1++;
			} else if (a[i] == 1) {
				can_1++;
			} else if (a[i] == -1) {
				can_n1++;
			}
			if (a[i] == 1) num_1++;
			if (a[i] == -1) num_n1++;
		}
		if (sum % 2) {
			cout << -1 << '\n';
			continue;
		}
		sum /= 2;
		if (num_1 > num_n1) {
			for (int i = 0; i < n; i++) a[i] *= -1;
			swap(can_1, can_n1);
			swap(num_1, num_n1);
		}
		vector<pair<int, int>> ans;
		int num_1_left = sum;
		int num_n1_left = sum;
		for (int i = 0; i < n - 1; i++) {
			if (num_n1 > sum && a[i + 1] == -1) {
				ans.emplace_back(i, i + 1);
				i++;
				if (i == n - 2) ans.emplace_back(n - 1, n - 1);
				num_n1--;
				continue;
			}
			ans.emplace_back(i, i);
			if (i == n - 2) ans.emplace_back(n - 1, n - 1);
		}
		if (n == 1) ans.emplace_back(0, 0);
		int s = 0;
		cout << ans.size() << '\n';
		for (pair<int, int> x : ans) {
			cout << x.first + 1 << ' ' << x.second + 1 << '\n';
		}
		if (n > 1) {
			for (pair<int, int> x : ans) {
				if (x.second - x.first == 1) {
					s += a[x.first] - a[x.second];
				} else {
					s += a[x.first];
				}
			}
			if (s != 0 || ans[0].first != 0 || ans[ans.size() - 1].second != n - 1) {
				debug(a);
				break;
			}
		}
	}
	debug("good");
}


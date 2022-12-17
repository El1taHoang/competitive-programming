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
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i].first;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].second;
		}
		sort(a.begin(), a.end());
		int min_x = 2e9;
		vector<int> suffix_max(n + 1, -2e9);
		for (int i = n - 1; i >= 0; i--) {
			suffix_max[i] = max(suffix_max[i + 1], a[i].first + a[i].second);
		}
		int min_dist = 2e9;
		int best_pos;
		for (int i = 0; i < n - 1; i++) {
			min_x = min(min_x, a[i].first - a[i].second);
			int max_x = suffix_max[i + 1];
			int dist1 = 2 * max(a[i].first - min_x, max_x - a[i].first);
			if (dist1 < min_dist) {
				min_dist = dist1;
				best_pos = 2 * a[i].first;
			}
			// a[i].first <= (max_x + min_x)/2 <= a[i + 1].first
			if (2 * a[i].first <= (max_x + min_x) && (max_x + min_x) <= 2 * a[i + 1].first) {
				int dist2 = (max_x - min_x);
				if (dist2 < min_dist) {
					min_dist = dist2;
					best_pos = max_x + min_x;
				}
			}
		}
		int dist3 = 2 * (a[n - 1].first - min_x);
		if (dist3 < min_dist) {
			min_dist = dist3;
			best_pos = 2 * a[n - 1].first;
		}
		cout << best_pos/2 << (best_pos % 2 != 0 ? ".5" : "") << '\n';
	}
}


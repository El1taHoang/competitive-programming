// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> intervals;
	for (int i = 0; i < n; i++) {
		int p2 = 1;
		while (i + p2 <= n) {
			intervals.emplace_back(i, i + p2);
			p2 *= 2;
		}
	}
	cout << intervals.size() << endl;
	for (int i = 0; i < intervals.size(); i++) {
		cout << intervals[i].first + 1 << ' ' << intervals[i].second << endl;
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		int p2 = 1;
		int seg1_r;
		while (p2 <= r - l) {
			seg1_r = l + p2;
			p2 *= 2;
		}
		p2 = 1;
		int seg2_l;
		while (p2 <= r - l) {
			seg2_l = r - p2;
			p2 *= 2;
		}
		int a = lower_bound(intervals.begin(), intervals.end(), make_pair(l, seg1_r)) - intervals.begin();
		int b = lower_bound(intervals.begin(), intervals.end(), make_pair(seg2_l, r)) - intervals.begin();
		cout << a + 1 << ' ' << b + 1 << endl;
	}
}

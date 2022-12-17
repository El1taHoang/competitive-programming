// Author: Aaron He
// Created: 17 July 2020
#include <bits/stdc++.h>
using namespace std;
 
struct SegmentTree {
	vector<long long> tree;
	int size;
	SegmentTree(int size) {
		int p2 = 1;
		while (p2 < size) {
			p2 *= 2;
		}
		tree.resize(p2 * 2);
		this->size = p2;
	}
	void build(vector<long long> &a, int i = 0, int lx = 0, int rx = -1) {
		if (rx == -1) {
			rx = size;
		}
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[i] = a[lx];
			}
			return;
		}
		int mid = (lx + rx)/2;
		build(a, 2 * i + 1, lx, mid);
		build(a, 2 * i + 2, mid, rx);
		tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
	}
	void set(int pos, long long val, int i = 0, int lx = 0, int rx = -1) {
		if (rx == -1) {
			rx = size;
		}
		if (rx - lx == 1) {
			tree[i] = val;
			return;
		}
		int mid = (lx + rx)/2;
		if (pos < mid) {
			set(pos, val, 2 * i + 1, lx, mid);
		} else {
			set(pos, val, 2 * i + 2, mid, rx);
		}
		tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
	}
	long long get(int l, int r, int i = 0, int lx = 0, int rx = -1) {
		if (rx == -1) {
			rx = size;
		}
		if (lx >= l && rx <= r) {
			return tree[i];
		}
		if (l >= rx || r <= lx) {
			return 0;
		}
		int mid = (lx + rx)/2;
		return get(l, r, 2 * i + 1, lx, mid) + get(l, r, 2 * i + 2, mid, rx);
	}
};
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	SegmentTree st(n);
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	st.build(a);
	while (m--) {
		int test;
		cin >> test;
		if (test == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		} else if (test == 2) {
			int l, r;
			cin >> l >> r;
			cout << st.get(l, r) << '\n';
		}
	}
}

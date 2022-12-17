// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
using namespace std;

class SegmentTree {
	private:
	int size;
	vector<pair<int, int>> tree;
	const pair<int, int> identity = make_pair(INT_MAX, 0);
	pair<int, int> func(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return {a.first, a.second + b.second};
		}
		if (a.first < b.first) {
			return a;
		}
		return b;
	}
	struct Node {
		int i, l, r;
		Node left() {
			return {2 * i + 1, l, (l + r)/2};
		}
		Node right() {
			return {2 * i + 2, (l + r)/2, r};
		}
		int length() {
			return r - l;
		}
		bool contains(int i) {
			return l <= i && i < r;
		}
		bool is_contained(int lb, int rb) {
			return lb <= l && r <= rb;
		}
		bool is_outside(int lb, int rb) {
			return r <= lb || rb <= l;
		}
	};
	void unite(Node n) {
		tree[n.i] = func(tree[n.left().i], tree[n.right().i]);
	}
	Node root() {
		return {0, 0, size};
	}
	public:
	SegmentTree(int size) {
		int p2 = 1;
		while (p2 < size) {
			p2 *= 2;
		}
		this->size = p2;
		tree.resize(2 * p2 - 1, identity);
	}
	void build(vector<int> &a, Node n) {
		if (n.length() == 1) {
			if (n.l < a.size()) {
				tree[n.i] = {a[n.l], 1};
			}
			return;
		}
		build(a, n.left());
		build(a, n.right());
		unite(n);
	}
	void build(vector<int> &a) {
		assert(a.size() <= size);
		build(a, root());
	}
	void set(int i, int v, Node n) {
		if (n.length() == 1) {
			tree[n.i] = {v, 1};
			return;
		}
		if (n.left().contains(i)) {
			set(i, v, n.left());
		} else {
			set(i, v, n.right());
		}
		unite(n);
	}
	void set(int i, int v) {
		assert(i >= 0 && i < size);
		set(i, v, root());
	}
	pair<int, int> get(int l, int r, Node n) {
		if (n.is_outside(l, r)) {
			return identity;
		}
		if (n.is_contained(l, r)) {
			return tree[n.i];
		}
		return func(get(l, r, n.left()), get(l, r, n.right()));
	}
	pair<int, int> get(int l, int r) {
		assert(l >= 0 && r <= size);
		return get(l, r, root());
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree st(n);
	st.build(a);
	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		} else {
			int l, r;
			cin >> l >> r;
			pair<int, int> res = st.get(l, r);
			cout << res.first << ' ' << res.second << '\n';
		}
	}
}

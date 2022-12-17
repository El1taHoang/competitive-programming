// Author: Aaron He
// Created: 17 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

struct Segment {
	vector<bool> has;
	int diff;
	Segment() {
		has = vector<bool>(41);
		diff = 0;
	}
};

#include <cassert>
template <typename T>
class SegmentTree {
	private:
	int size;
	vector<T> tree;
	const T identity = {};
	T func(T a, T b) {
		T res;
		for (int i = 1; i < a.has.size(); i++) {
			res.has[i] = a.has[i] || b.has[i];
			res.diff += res.has[i];
		}
		return res;
	}
	template <typename U>
	T construct_leaf(U v) {
		T res;
		res.has[v] = true;
		res.diff = 1;
		return res;
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
	template <typename U>
	void build(vector<U> &a, Node n) {
		if (n.length() == 1) {
			if (n.l < a.size()) {
				tree[n.i] = construct_leaf(a[n.l]);
			}
			return;
		}
		build(a, n.left());
		build(a, n.right());
		unite(n);
	}
	template <typename U>
	void build(vector<U> &a) {
		assert(a.size() <= size);
		build(a, root());
	}
	template <typename U>
	void set(int i, U v, Node n) {
		if (n.length() == 1) {
			tree[n.i] = construct_leaf(v);
			return;
		}
		if (n.left().contains(i)) {
			set(i, v, n.left());
		} else {
			set(i, v, n.right());
		}
		unite(n);
	}
	template <typename U>
	void set(int i, U v) {
		assert(i >= 0 && i < size);
		set(i, v, root());
	}
	template <typename U>
	void add(int i, U v, Node n) {
		if (n.length() == 1) {
			tree[n.i] = func(tree[n.i], v);
			return;
		}
		if (n.left().contains(i)) {
			add(i, v, n.left());
		} else {
			add(i, v, n.right());
		}
		unite(n);
	}
	template <typename U>
	void add(int i, U v) {
		assert(i >= 0 && i < size);
		add(i, v, root());
	}
	T get(int l, int r, Node n) {
		if (n.is_outside(l, r)) {
			return identity;
		}
		if (n.is_contained(l, r)) {
			return tree[n.i];
		}
		return func(get(l, r, n.left()), get(l, r, n.right()));
	}
	T get(int l, int r) {
		assert(l >= 0 && r <= size);
		return get(l, r, root());
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	SegmentTree<Segment> st(n);
	st.build(a);
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y;
			cin >> x >> y;
			x--;
			Segment res = st.get(x, y);
			cout << res.diff << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			x--;
			st.set(x, y);
		}
	}
}

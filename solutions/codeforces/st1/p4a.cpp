// Author: Aaron He
// Created: 16 December 2022 (Friday)
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>
using namespace std;

template <typename T>
class SegmentTree {
	private:
	int size;
	vector<T> tree;
	const T identity = 0;
	T func(T a, T b) {
		return a + b;
	}
	T construct_leaf(int v) {
		return v;
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
				tree[n.i] = construct_leaf(a[n.l]);
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
	void set(int i, int v) {
		assert(i >= 0 && i < size);
		set(i, v, root());
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
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	SegmentTree<int> st(n + 1);
	for (int i = 0; i < n; i++) {
		st.set(p[i], 1);
		cout << st.get(p[i] + 1, n + 1) << " \n"[i == n - 1];
	}
}

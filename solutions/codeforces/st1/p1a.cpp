// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class SegmentTree {
	private:
	int size;
	vector<long long> tree;
	const long long identity = 0;
	long long func(long long a, long long b) {
		return a + b;
	}
	void unite(int x) {
		tree[x] = func(tree[2 * x + 1], tree[2 * x + 2]);
	}
	public:
	SegmentTree(int size) {
		this->size = 1;
		while (this->size < size) {
			this->size *= 2;
		}
		tree.resize(2 * this->size - 1, identity);
	}
	void build(vector<int> &a, int x, int lb, int rb) {
		if (rb - lb == 1) {
			if (lb < a.size()) {
				tree[x] = a[lb];
			}
			return;
		}
		int mb = (lb + rb)/2;
		build(a, 2 * x + 1, lb, mb);
		build(a, 2 * x + 2, mb, rb);
		unite(x);
	}
	void build(vector<int> &a) {
		assert(a.size() <= size);
		build(a, 0, 0, size);
	}
	void set(int i, int v, int x, int lb, int rb) {
		if (rb - lb == 1) {
			tree[x] = v;
			return;
		}
		int mb = (lb + rb)/2;
		if (i < mb) {
			set(i, v, 2 * x + 1, lb, mb);
		} else {
			set(i, v, 2 * x + 2, mb, rb);
		}
		unite(x);
	}
	void set(int i, int v) {
		assert(i >= 0 && i < size);
		set(i, v, 0, 0, size);
	}
	long long get(int l, int r, int x, int lb, int rb) {
		if (r <= lb || rb <= l) {
			return identity;
		}
		if (l <= lb && rb <= r) {
			return tree[x];
		}
		long long mb = (lb + rb)/2;
		return func(get(l, r, 2 * x + 1, lb, mb), get(l, r, 2 * x + 2, mb, rb));
	}
	long long get(int l, int r) {
		assert(l >= 0 && r <= size);
		return get(l, r, 0, 0, size);
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
			cout << st.get(l, r) << '\n';
		}
	}
}

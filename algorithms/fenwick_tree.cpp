/*
Author: Aaron He
Created: 1 July 2020
*/
#include <vector>
template <typename T>
class FenwickTree {
	vector<T> tree;
	public:
	int size;
	FenwickTree(int size) {
		this->size = size;
		tree.resize(size + 1);
	}
	void update(int pos, T val) {
		pos++;
		while (pos <= size) {
			tree[pos] += val;
			pos += pos & (-pos);
		}
	}
	T query(int pos) {
		pos++;
		T res = 0;
		while (pos) {
			res += tree[pos];
			pos -= pos & (-pos);
		}
		return res;
	}
};
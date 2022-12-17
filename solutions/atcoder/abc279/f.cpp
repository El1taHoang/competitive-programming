// Author: Aaron He
// Created: 26 November 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

// Credit: https://cp-algorithms.com/data_structures/disjoint_set_union.html
vector<int> parent;
vector<int> set_size;
void make_set(int u) {
	parent[u] = u;
	set_size[u] = 1;
}

int find_set(int u) {
	if (u == parent[u]) {
		return u;
	}
	int p = find_set(parent[u]);
	parent[u] = p;
	return p;
}

void union_sets(int u, int v) {
	u = find_set(u);
	v = find_set(v);
	if (u != v) {
		if (set_size[u] > set_size[v]) {
			swap(u, v);
		}
		parent[u] = v;
		set_size[v] += set_size[u];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	parent = vector<int>(n + 1 + q + q);
	set_size = vector<int>(n + 1 + q + q);
	vector<int> set_to_box(n + 1 + q + q);
	vector<int> box_to_set(n + 1 + q + q);
	int k = n;
	int cur = n + q;
	for (int i = 1; i < parent.size(); i++) {
		make_set(i);
		set_to_box[i] = i;
		box_to_set[i] = i;
	}
	while (q--) {
		int query;
		cin >> query;
		if (query == 1) {
			int x, y;
			cin >> x >> y;
			cur++;
			union_sets(box_to_set[y], box_to_set[x]);
			set_to_box[find_set(box_to_set[x])] = x;
			box_to_set[x] = find_set(box_to_set[x]);
			set_to_box[cur] = y;
			box_to_set[y] = cur;
		} else if (query == 2) {
			int x;
			cin >> x;
			k++;
			union_sets(box_to_set[x], k);
			set_to_box[k] = x;
			box_to_set[x] = k;
			debug(find_set(x), x);
		} else if (query == 3) {
			int x;
			cin >> x;
			cout << set_to_box[find_set(x)] << '\n';
		}
		debug(query, parent);
	}
}

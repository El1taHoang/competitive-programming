#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct ft {
	vector<int> tree;
	int size;
	ft (int size) {
		this->size = size;
		tree.resize(size + 1);
	}
	void add(int pos, int val) {
		pos = size - pos;
		while (pos <= size) {
			tree[pos] += val;
			pos += pos & -pos;
		}
	}
	int get(int pos) {
		pos = size - pos;
		int res = 0;
		while (pos) {
			res += tree[pos];
			pos -= pos & -pos;
		}
		return res;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	segtree st(n);
	st.build(b);
	long long ans = 0;
	int cur_len = 1;
	vector<int> longest(n);
	for (int i = 0; i < n; i++) {
		if (a[i] < cur_len) {
			cur_len = a[i];
		}
		longest[i] = cur_len;
		ans += cur_len;
		b[i] = longest[i] - (a[i] - i);
		cur_len++;
	}
	vector<long long> plongest(n + 1);
	for (int i = 0; i < n; i++) {
		plongest[i + 1] = plongest[i] + longest[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int p, x;
		cin >> p >> x;
		p--;
		if (p) {
			x = min(x, longest[p - 1] + 1);
		} else {
			x = min(x, 1);
		}
		int find = x - p;
		int l = p;
		int r = n;
		while (l < r) {
			int m = (l + r + 1)/2;
			if (min(find, st.get_min(p + 1, m)) >= find) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		cout << (ans - (plongest[l] - plongest[p]) + 1ll * (2 * x + (l - p) - 1) * (l - p)/2) << '\n';
	}
}


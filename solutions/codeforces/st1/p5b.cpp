// Author: Aaron He
// Created: 16 December 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <cassert>
#include <vector>
 
int mod;
class Mint {
	public:
	//static const int mod = 1e9 + 7;
	//static const int mod = 998244353;
	private:
	int val = 0;
	int normalize(long long x) {
		int res = x % mod;
		return res + (res < 0 ? mod : 0);
	}
	public:
	Mint() {}
	Mint(long long val) {
		(*this).val = normalize(val);
	}
	Mint pow(long long pow) {
		Mint base = val;
		if (pow < 0) {
			Mint inv_base = base.pow(mod - 2);
			return inv_base.pow(-pow);
		}
		Mint res = 1;
		while (pow) {
			if (pow % 2) {
				res *= base;
			}
			base *= base;
			pow /= 2;
		}
		return res;
	}
	explicit operator int() const {
		return val;
	}
	Mint operator-() {
		Mint result = -val;
		return result;
	}
	friend Mint operator+(const Mint &a, const Mint &b);
	friend Mint operator-(const Mint &a, const Mint &b);
	friend Mint operator*(const Mint &a, const Mint &b);
	friend Mint operator/(const Mint &a, const Mint &b);
	Mint operator+=(const Mint &other) {
		*this = *this + other;
		return *this + other;
	}
	Mint operator-=(const Mint &other) {
		*this = *this - other;
		return *this - other;
	}
	Mint operator*=(const Mint &other) {
		*this = *this * other;
		return *this * other;
	}
	Mint operator/=(const Mint &other) {
		*this = *this/other;
		return *this/other;
	}
	Mint operator++() {
		val = normalize(val + 1);
		Mint result = val;
		return result;
	}
	Mint operator--() {
		val = normalize(val - 1);
		Mint result = val;
		return result;
	}
	Mint operator++(int) {
		Mint result = val;
		val = normalize(val + 1);
		return result;
	}
	Mint operator--(int) {
		Mint result = val;
		val = normalize(val - 1);
		return result;
	}
	friend std::string to_string(Mint mint);
	friend bool operator==(const Mint &a, const Mint &b);
	friend bool operator!=(const Mint &a, const Mint &b);
	friend bool operator<(const Mint &a, const Mint &b);
	friend bool operator<=(const Mint &a, const Mint &b);
	friend bool operator>(const Mint &a, const Mint &b);
	friend bool operator>=(const Mint &a, const Mint &b);
	friend std::ostream& operator<<(std::ostream& stream, const Mint& mint);
	friend std::istream& operator>>(std::istream& stream, const Mint& mint);
};
std::string to_string(Mint mint) {
	return to_string(mint.val);
}
std::ostream& operator<<(std::ostream& stream, const Mint& mint) {
	stream << mint.val;
	return stream;
}
std::istream& operator>>(std::istream& stream, Mint& mint) {
	int val;
	stream >> val;
	mint = val;
	return stream;
}
Mint operator+(const Mint &a, const Mint &b) {
	Mint result = a.val + b.val;
	return result;
}
Mint operator-(const Mint &a, const Mint &b) {
	Mint result = a.val - b.val;
	return result;
}
Mint operator*(const Mint &a, const Mint &b) {
	Mint result = (long long) a.val * (long long) b.val;
	return result;
}
Mint operator/(const Mint &a, const Mint &b) {
	Mint result = a.val * Mint(b.val).pow(-1);
	return result;
}
bool operator==(const Mint &a, const Mint &b) {
	return a.val == b.val;
}
bool operator!=(const Mint &a, const Mint &b) {
	return a.val != b.val;
}
bool operator<(const Mint &a, const Mint &b) {
	return a.val < b.val;
}
bool operator<=(const Mint &a, const Mint &b) {
	return a.val <= b.val;
}
bool operator>(const Mint &a, const Mint &b) {
	return a.val > b.val;
}
bool operator>=(const Mint &a, const Mint &b) {
	return a.val >= b.val;
}
 
Mint pow(Mint a, long long b) {
	return a.pow(b);
}
 
std::vector<Mint> fact_arr;
std::vector<Mint> ifact_arr;

void update_factorial_arrays(int n) {
	while ((int)fact_arr.size() <= n) {
		if (fact_arr.empty()) {
			fact_arr.push_back(1);
			ifact_arr.push_back(1);
		}
		fact_arr.push_back(fact_arr.back() * (Mint)fact_arr.size());
		ifact_arr.push_back(ifact_arr.back()/(Mint)ifact_arr.size());
	}
}
Mint fact(int n) {
	assert(n >= 0);
	update_factorial_arrays(n);
	return fact_arr[n];
}
Mint ifact(int n) {
	assert(n >= 0);
	update_factorial_arrays(n);
	return ifact_arr[n];
}
 
Mint nck(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return fact(n) * ifact(k) * ifact(n - k);
}
 
Mint npk(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return fact(n) * ifact(n - k);
}

struct matrix {
	Mint a11, a12, a21, a22;
};

#include <cassert>
template <typename T>
class SegmentTree {
	private:
	int size;
	vector<T> tree;
	const T identity = {1, 0, 0, 1};
	T func(T a, T b) {
		T res = {a.a11 * b.a11 + a.a12 * b.a21, a.a11 * b.a12 + a.a12 * b.a22, a.a21 * b.a11 + a.a22 * b.a21, a.a21 * b.a12 + a.a22 * b.a22};
		return res;
	}
	template <typename U>
	T construct_leaf(U v) {
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> mod >> n >> m;
	vector<matrix> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].a11 >> a[i].a12 >> a[i].a21 >> a[i].a22;
	}
	SegmentTree<matrix> st(n);
	st.build(a);
	while (m--) {
		int l, r;
		cin >> l >> r;
		l--;
		matrix res = st.get(l, r);
		cout << res.a11 << ' ' << res.a12 << '\n';
		cout << res.a21 << ' ' << res.a22 << '\n';
		cout << '\n';
	}
}

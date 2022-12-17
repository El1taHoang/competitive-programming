// Author: Aaron He
// Created: 25 November 2022 (Friday)
#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <cassert>
#include <vector>
 
class Mint {
	private:
	int val = 0;
	// Choose mod then hit Ctrl-o
	static const int mod = 1e9 + 7;
	//static const int mod = 998244353;
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
 
std::vector<Mint> fact_arr(1, 1);
std::vector<Mint> ifact_arr(1, 1);
Mint fact(int n) {
	assert(n >= 0);
	while ((int)fact_arr.size() <= n) {
		fact_arr.push_back(fact_arr.back() * (Mint)fact_arr.size());
		ifact_arr.push_back(ifact_arr.back()/(Mint)ifact_arr.size());
	}
	return fact_arr[n];
}
Mint ifact(int n) {
	assert(n >= 0);
	while ((int)ifact_arr.size() <= n) {
		fact_arr.push_back(fact_arr.back() * (Mint)fact_arr.size());
		ifact_arr.push_back(ifact_arr.back()/(Mint)ifact_arr.size());
	}
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

int mod(int a, int b) {
	return (a % b + b) % b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m, h;
		cin >> n >> m >> h;
		vector<vector<int>> a(n, vector<int>(m));
		bool all_unknown = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				if (a[i][j] != -1) {
					all_unknown = false;
				}
			}
		}
		Mint ans = all_unknown ? h : 1;
		vector<int> row_diff(n - 1, -1);
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m; j++) {
				int diff = mod(a[i + 1][j] - a[i][j], h);
				if (a[i + 1][j] != -1 && a[i][j] != -1) {
					if (row_diff[i] == -1) {
						row_diff[i] = diff;
					} else if (row_diff[i] != diff) {
						ans = 0;
					}
				}
			}
		}
		vector<int> col_diff(m - 1, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m - 1; j++) {
				int diff = mod(a[i][j + 1] - a[i][j], h);
				if (a[i][j + 1] != -1 && a[i][j] != -1) {
					if (col_diff[i] == -1) {
						col_diff[i] = diff;
					} else if (col_diff[i] != diff) {
						ans = 0;
					}
				}
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (row_diff[i] != -1) {
				for (int j = 0; j < m; j++) {
					if (a[i][j] != -1) {
						a[i + 1][j] = 0;
					}
					if (a[i + 1][j] != -1) {
						a[i][j] = 0;
					}
				}
			}
		}
		for (int j = 0; j < m - 1; j++) {
			if (col_diff[j] != -1) {
				for (int i = 0; i < n; i++) {
					if (a[i][j] != -1) {
						a[i][j + 1] = 0;
					}
					if (a[i][j + 1] != -1) {
						a[i][j] = 0;
					}
				}
			}
		}
		int steps = 0;
		for (int i = 0; i < n - 1; i++) {
			steps++;
			if (row_diff[i] != -1) {
				row_diff[i] = 0;
				for (int j = 0; j < m; j++) {
					if (a[i][j] != -1) {
						a[i + 1][j] = 0;
					}
					if (a[i + 1][j] != -1) {
						a[i][j] = 0;
					}
				}
			}
		}
		ans *= pow(h, steps);
		cout << ans << '\n';
	}
}

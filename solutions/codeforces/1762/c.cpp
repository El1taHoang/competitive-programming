// Author: Aaron He
// Created: 15 December 2022 (Thursday)
#include <iostream>
#include <vector>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

#include <iostream>
#include <cassert>
#include <vector>
 
class Mint {
	public:
	//static const int mod = 1e9 + 7;
	static const int mod = 998244353;
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

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		Mint ans = 1;
		Mint ways = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) {
				ways *= 2;
			} else {
				ways = 1;
			}
			ans += ways;
			debug(i, ways);
		}
		cout << ans << '\n';
	}
}

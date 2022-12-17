// Author: Aaron He
// Created: 10 December 2022 (Saturday)
#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <cassert>
#include <vector>

int mod;
 
class Mint {
	public:
	int val = 0;
	int normalize(long long x) {
		int res = x % mod;
		return res + (res < 0 ? mod : 0);
	}
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

int main() {
	int n;
	cin >> n >> mod;
	Mint ans = 0;
	for (int d = 2; d < n; d++) {
		Mint cur = fact(d - 2);
		int free = n - (d + 1);
		cur *= pow(4, 
	}
}

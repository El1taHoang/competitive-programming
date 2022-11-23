/*
Author: Aaron He
Created: 22 November 2022 (Tuesday)

Learning to write a modular int class:
	- Inspiration from tourist's code
	- Videos from The Cherno:
		1. CLASSES in C++
		2. OPERATORS and OPERATOR OVERLOADING in C++
		3. Copying and Copy Constructors in C++

Notes:
	- Constructor automatically casts ints and long longs
	- Explicit casting is defined for ints
	- Only works for prime moduli when using division (using Fermat's little theorem)
	- Values should always be between 0 and mod - 1, excluding intermediate steps
	- Supported unary operations: -, ++, --, ++ (postfix), -- (postfix) 
	- Supported binary operations (format: Mint/int operator Mint/int): +, -, *, /, ==, !=, <, <=, >, >=
	- Supported binary operations (format: Mint operator Mint/int): +=, -=, *=, /=, .pow
	- Supported binary operations (format: stream operator Mint): >>, <<
	- Binomial coefficients and factorials are also defined
	- Negative powers are now supported
	- Factorial will cache all results until it needs to compute more
*/

#include <iostream>
#include <cassert>
#include <vector>

class Mint {
	private:
	long long val;
	// Choose mod then hit Ctrl-o
	//static const int mod = 1e9 + 7;
	//static const int mod = 998244353;
	int normalize(long long x) {
		return (x % mod + mod) % mod;
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
	Mint result = a.val * b.val;
	return result;
}
Mint operator/(const Mint &a, const Mint &b) {
	assert(b != 0);
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

std::vector<Mint> fact_arr;
Mint factorial(int n) {
	assert(n >= 0);
	if (!fact_arr.size()) {
		fact_arr.push_back(1);
	}
	while ((int)fact_arr.size() <= n) {
		fact_arr.push_back(fact_arr.back() * (Mint)fact_arr.size());
	}
	return fact_arr[n];
}

Mint choose(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return factorial(n)/factorial(k)/factorial(n - k);
}

Mint permute(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return factorial(n)/factorial(n - k);
}

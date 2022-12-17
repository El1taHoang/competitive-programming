// Author: Aaron He
// Created: 6 December 2022 (Tuesday)
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
	private:
	int val = 0;
	// Choose mod then hit Ctrl-o
	//static const int mod = 1e9 + 7;
	static const int mod = 998244353;
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// ans = e(monster ends with 0 stamina or monster ends with -1 stamina with last hit taking 2 stamina)
	int n;
	cin >> n;
	Mint p;
	cin >> p;
	p /= 100;
	// dp[i][h] = probability of h hits to get to i health
	// dp[i][h] = dp[i + 1][h - 1] * (1 - p) + dp[i + 2][h - 1] * p
	// e[i] = expected value to get to i health
	// e[i] = sum h, h * dp[i][h]
	// e[i] = sum h, h * dp[i + 1][h - 1] * (1 - p) + h * dp[i + 2][h - 1] * p
	// e[i] = sum h, (h - 1 + 1) * dp[i + 1][h - 1] * (1 - p) + (h - 1 + 1) * dp[i + 2][h - 1] * p
	// e[i] = sum h, e[i + 1] * (1 - p) + dp[i + 1][h - 1] + e[i + 2] * p +  dp[i + 2][h - 1]
	// e[i] = p[i + 1] + p[i + 2] + sum h, p * e[i + 1] * (1 - p) + e[i + 2]
	// p[i] = probability of ever getting to i health
	vector<Mint> e(n + 1);
	vector<Mint> P(n + 1);
	P[n] = 1;
	e[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		P[i] = (1 - p) * P[i + 1];
		if (i + 2 <= n) {
			P[i] += p * P[i + 2];
		}
		if (i == 0) {
			P[i] += p * P[i + 1];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		e[i] = (1 - p) * (P[i + 1] + e[i + 1]);
		if (i + 2 <= n) {
			e[i] += p * (P[i + 2] + e[i + 2]);
		}
		if (i == 0) {
			e[i] += p * (P[i + 1] + e[i + 1]);
		}
	}
	debug(e, P);
	cout << e[0] << '\n';
}

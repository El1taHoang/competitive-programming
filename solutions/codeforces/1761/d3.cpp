// Author: Aaron He
// Created: 22 November 2022 (Tuesday)
#include <iostream>
#include <vector>
using namespace std;
 
#include <iostream>
#include <cassert>
#include <vector>
 
class Mint {
	private:
	int val;
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
	Mint pow(int pow) {
		Mint base = val;
		if (pow < 0) {
			Mint inv_base = base.pow(mod - 2);
			return inv_base.pow(-pow);
		}
		Mint res = 1;
		while (pow) {
			if (pow & 1) {
				res *= base;
			}
			base *= base;
			pow >>= 1;
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
 
Mint pow(Mint a, long long b) {
	return a.pow(b);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		cout << pow(3, n) << '\n';
		return 0;
	}
	Mint ans = 0;
	for (int i = 1; i <= k; i++) {
		Mint carry = nck(k - 1, i - 1);
		Mint cases = 0;
		cases += pow(3, n - i - (i - 1)) * nck((n - k) - 1, (i - 1) - 1);
		cases += pow(3, n - i - (i - 1)) * nck((n - k) - 1, i - 1);
		cases += pow(3, n - i - i) * nck((n - k) - 1, i - 1);
		cases += pow(3, n - i - i) * nck((n - k) - 1, (i + 1) - 1);
		ans += cases * carry;
	}
	cout << ans << '\n';
}

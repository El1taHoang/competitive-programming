// Author: Aaron He
// Created: 26 November 2022 (Saturday)
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// min(a/sqrt(x) + b * x - b), x >= 1
	// -1/2 * a * x^(-3/2) + b = 0
	// x = (2b/a)^2/3
	long long a, b;
	cin >> a >> b;
	double x = pow((2.0 * b)/a, -2.0/3);
	double ans = a;
	for (long long i = max((long long)x - 1, 1ll); i <= x + 1; i++) {
		ans = min(ans, a/sqrt(i) + b * (i - 1));
		debug(i, ans);
	}
	cout << fixed << setprecision(15) << ans << '\n';
}

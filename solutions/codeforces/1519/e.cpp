#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct frac {
	long long n, d;
	frac(int n, int d) {
		this->n = n;
		this->d = d;
		long long c = __gcd(n, d);
		n /= c;
		d /= c;
	}
	bool equals(frac f) {
		return n == f.n && d == f.d;
	}
	bool operator<(const frac &f) const {
		if (n != f.n) {
			return n < f.n;
		}
		return d < f.d;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<frac, int> comp;
	vector<int> comp_count(n + 1);
	int ncomp = 0;
	for (int i = 0; i < n; i++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		frac f1 = frac(b * (c + d), a * d);
		frac f2 = frac(b * c, (a + b) * d);
		if (!comp[f1] && !comp[f2]) {
			ncomp++;
		}
		comp[f1] = comp[f2] = ncomp;
		comp_count[ncomp]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += comp_count[i]/2;
	}
	cout << ans << '\n';
}

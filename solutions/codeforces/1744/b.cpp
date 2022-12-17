#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		vector<long long> a(n);
		long long sum = 0;
		int n_even = 0, n_odd = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			if (a[i] % 2 == 0) {
				n_even++;
			} else {
				n_odd++;
			}
		}
		while (q--) {
			int type, x;
			cin >> type >> x;
			if (type == 0) {
				sum += x * n_even;
				if (x % 2 == 1) {
					n_odd += n_even;
					n_even = 0;
				}
			} else {
				sum += x * n_odd;
				if (x % 2 == 1) {
					n_even += n_odd;
					n_odd = 0;
				}
			}
			cout << sum << '\n';
		}
	}
}


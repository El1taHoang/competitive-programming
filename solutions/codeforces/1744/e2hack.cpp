#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return n >= 2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; 1ll * i * i < 5e8; i++) {
		if (is_prime(i)) {
			long long j = 1ll * i * i;
			cout << j << ' ' << j << ' ' << 2 * j << ' ' << 2 * j << '\n';
		}
	}
}


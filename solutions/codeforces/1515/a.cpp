#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vector<int> w(n);
		int sum = 0;
		bool good = false;
		for (int i = 0; i < n; i++) {
			cin >> w[i];
			if (w[i] != x) {
				good = true;
			}
			sum += w[i];
		}
		if (sum == x || !good) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			sort(w.begin(), w.end());
			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += w[i];
				if (sum == x) {
					if (i < n - 1) {
						swap(w[i], w[i + 1]);
						sum += w[i + 1] - w[i];
					}
				}	
			}
			for (int i = 0; i < n; i++) {
				cout << w[i] << " \n"[i == n - 1];
			}
		}
	}
}


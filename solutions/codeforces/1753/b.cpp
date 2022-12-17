#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> count(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= n) {
			count[a[i]]++;;
		}
	}
	if (x > n) {
		cout << (*min_element(a.begin(), a.end()) >= x ? "Yes" : "No") << '\n';
		return 0;
	}
	bool ans = true;
	for (int i = 0; i < x; i++) {
		count[i + 1] += count[i]/(i + 1);
		count[i] %= i + 1;
		if (count[i]) {
			ans = false;
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << '\n';
}


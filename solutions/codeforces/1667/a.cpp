#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long best_ans = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		long long cur = 0;
		long long ans = 0;
		for (int j = i - 1; j >= 0; j--) {
			ans += cur/a[j] + 1;
			cur = (cur/a[j] + 1) * a[j];
		}
		cur = 0;
		for (int j = i + 1; j < n; j++) {
			ans += cur/a[j] + 1;
			cur = (cur/a[j] + 1) * a[j];
		}
		best_ans = min(ans, best_ans);
	}
	cout << best_ans << '\n';
}


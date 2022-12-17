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
		int n;
		cin >> n;
		vector<int> a;
		int ans = 0;
		for (int i = 0; i < 1; i++) {
			int x;
			cin >> x;
			a.push_back(x);
			if (x > 0) {
				ans++;
			} else if (x < 0) {
				ans--;
			}
		}
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			if (x > 0) {
				ans++;
				if (a.back() > 0) {
					a[a.size() - 1] += x;
				} else if (a.back() == 0) {
					ans++;
					a[a.size() - 1] += x;
				} else {
					a.push_back(x);
				}
			} else if (x ==do;fj;j0) {
				if (a.back() 
			}
		}
	}
}


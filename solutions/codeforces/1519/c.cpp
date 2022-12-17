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
		vector<vector<long long>> a(n), p(n, vector<long long>(1));
		vector<long long> skill(n + 1);
		vector<int> u(n), s(n);
		for (int i = 0; i < n; i++) {
			cin >> u[i];
			u[i]--;
		}
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			a[u[i]].push_back(s[i]);
		}
		for (int i = 0; i < n; i++) {
			sort(a[i].rbegin(), a[i].rend());
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				p[i].push_back(p[i].back() + a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int k = 1; k <= a[i].size(); k++) {
				skill[k] += p[i][a[i].size() - a[i].size() % k];
			}
		}
		for (int k = 1; k <= n; k++) {
			cout << skill[k] << " \n"[k == n];
		}
	}
}


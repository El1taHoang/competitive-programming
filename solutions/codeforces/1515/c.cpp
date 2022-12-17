#include <queue>
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
		int n, m, x;
		cin >> n >> m >> x;
		vector<int> h(n), assign(n), tower(m);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		for (int i = 0; i < m; i++) {
			pq.push({0, i});
		}
		for (int i = 0; i < n; i++) {
			pair<int, int> p = pq.top();
			pq.pop();
			assign[i] = p.second;
			p.first += h[i];
			pq.push(p);
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			cout << assign[i] + 1 << " \n"[i == n - 1];
		}
	}
}

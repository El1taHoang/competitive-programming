#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int INF = n + 1;
	vector<vector<int>> dp0(n + 1, vector<int>(m + 1, INF));
	vector<vector<int>> dp1(n + 1, vector<int>(m + 1, INF));
	dp1[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = a[i - 1]; j <= m; j++) {
			dp1[i][j] = min(dp1[i][j], dp1[i - 1][j - a[i - 1]]);
			dp1[i][j] = min(dp1[i][j], dp0[i - 1][j - a[i - 1]]);
		}
		for (int j = 0; j <= m; j++) {
			dp0[i][j] = min(dp0[i][j], dp1[i - 1][j] + 1);
			dp0[i][j] = min(dp0[i][j], dp0[i - 1][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		int best = min(dp0[n][i], dp1[n][i]);
		cout << (best == INF ? -1 : best) << '\n';
	}
}


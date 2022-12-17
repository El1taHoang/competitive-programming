#include <cassert>
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
		vector<string> s(3);
		vector<vector<int>> count(3, vector<int>(2));
		for (int i = 0; i < 3; i++) {
			cin >> s[i];
			for (char c : s[i]) {
				count[i][c - '0']++;
			}
		}
		string res;
		for (int d = 0; d < 2; d++) {
			for (int i = 0; i < 3; i++) {
				for (int j = i + 1; j < 3; j++) {
					if (count[j][d] >= n && count[i][d] >= n) {
						string ans = "";
						int p0 = 0;
						for (int p1 = 0; p1 < 2 * n; p1++) {
							if (s[i][p0] - '0' == d && s[i][p2] - '0't == d) {
							}
						}
					}
				}
			}
		}
		assert(res.size());
		cout << res << '\n';
	}
}

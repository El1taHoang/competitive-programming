#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		char c;
		string s;
		cin >> n >> c >> s;
		s += s;
		vector<int> pos_g;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'g') pos_g.push_back(i);
		}
		int j = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == c) {
				while (pos_g[j] < i) {
					j++;
				}
				ans = max(ans, pos_g[j] - i);
			}
		}
		cout << ans << '\n';
	}
}


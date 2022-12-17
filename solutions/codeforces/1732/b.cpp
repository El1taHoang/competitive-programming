#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <climits>
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
		string s;
		cin >> n >> s;
		vector<int> prefix(n + 1);
		vector<char> blocks;
		blocks.push_back(s[0]);
		for (int i = 0; i < n; i++) {
			if (s[i] != blocks.back()) {
				blocks.push_back(s[i]);
			}
		}
		int ans = blocks.size();
		ans--;
		if (ans == 0) {
			cout << ans << '\n';
			continue;
		}
		if (blocks[0] == '0') {
			ans--;
		}
		cout << ans << '\n';
	}
}


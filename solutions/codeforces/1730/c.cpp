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
		string s;
		cin >> s;
		vector<int> suffix_min(s.size() + 1, 2e9);
		vector<int> suffix_min_i(s.size() + 1, -1);
		for (int i = (int)s.size() - 1; i >= 0; i--) {
			suffix_min[i] = min(suffix_min[i + 1], (int)s[i]);
			suffix_min_i[i] = suffix_min_i[i + 1];
			if ((int)s[i] <= suffix_min[i + 1]) {
				suffix_min_i[i] = i;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (i != suffix_min_i[i]) {
				s[i] = min('9', (char)(s[i] + 1));
			}
		}
		sort(s.begin(), s.end());
		cout << s << '\n';
	}
}


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
		vector<int> pos(26, -1);
		int mx_pos = 2e9;
		string s, result;
		cin >> s;
		vector<vector<int>> count(s.size(), vector<int>(26));
		vector<bool> used(26);
		vector<bool> good(s.size());
		for (int i = 0; i < s.size(); i++) {
			count[0][s[i] - 'a']++;
		}
		char best = 0;
		int best_i;
		for (int i = 0; i < s.size(); i++) {
			if (!good[i]) {
				good[i] = true;
				if (i) {
					for (int d = 0; d < 26; d++) {
						count[i][d] = count[i - 1][d];
					}
				}
				count[i][s[i] - 'a']--;
			}
			if (!used[s[i] - 'a'] && s[i] > best) {
				best = s[i];
				best_i = i;
			}
			if (count[i][s[i] - 'a'] == 0 && !used[s[i] - 'a']) {
				i = best_i;
				result += best;
				used[best - 'a'] = true;
				best = 0;
			}
		}
		cout << result << '\n';
	}
}


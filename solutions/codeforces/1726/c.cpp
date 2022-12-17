#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ()()()()()()((()))
int solve(string &s, int start, int end, vector<int>& matching) {
	if (start >= end) {
		return 0;
	}
	// cout << start << ' ' << end << '\n';
	int ans = 1;
	int count = 0; // # of ( - # of )
	int i = start;
	while (i < end) {
		ans += solve(s, i + 1, matching[i], matching);
		i = matching[i] + 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> matching(s.size());
		int previous = 0;
		int count = 0;
		stack<int> opening;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				opening.push(i);
			} else {
				int j = opening.top();
				opening.pop();
				matching[j] = i;
			}
		}
		cout << solve(s, 0, s.size(), matching) << '\n';
	}
}


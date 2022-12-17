#include <map>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	map<long long, long long> ans_before;
	map<long long, set<long long>> removed;
	map<long long, set<long long>> divisors;
	set<long long> s;
	s.insert(0);
	while (q--) {
		char query;
		cin >> query;
		if (query == '+') {
			long long x;
			cin >> x;
			s.insert(x);
			for (long long d : divisors[x]) {
				if (removed[d].count(x)) {
					removed[d].erase(x);
				}
			}
		} else if (query == '-') {
			long long x;
			cin >> x;
			for (long long d : divisors[x]) {
				removed[d].insert(x);
			}
			s.erase(x);
		} else {
			long long k;
			cin >> k;
			long long ans = ans_before[k];
			while (s.count(ans) && !removed[1].count(ans)) {
				divisors[ans].insert(k);
				ans += k;
			}
			ans_before[k] = ans;
			if (removed[k].size()) {
				ans = min(ans, *removed[k].begin());
			}
			cout << ans << '\n';
		}
	}
}


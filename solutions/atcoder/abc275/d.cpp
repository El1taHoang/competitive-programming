#include <map>
#include <iostream>
#include <vector>
using namespace std;

map<long long, long long> dp;
int solve(long long n) {
	long long ans = 0;
	if (dp[n]) {
		ans = dp[n];
	} else {
		ans = solve(n/2) + solve(n/3);
	}
	dp[n] = ans;
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	long long n;
	cin >> n;
	cout << solve(n) << '\n';
}


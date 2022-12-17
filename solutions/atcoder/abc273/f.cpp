// Author: Aaron He
// Created: 3 November 2022 (Thursday)
#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Based off editorial solution and Gennady Korotkevich's submission
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> events(2 * n); // events[i] = {x coordinate, type}, type = 0 if wall, 1 if hammer, 2 if goal
	for (int i = 0; i < n; i++) {
		cin >> events[i].first;
		events[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> events[n + i].first;
		events[n + i].second = ~i; // ~i = -i - 1 is distinct with all i from 0 to -1, and ~~i = i
	}
	events.emplace_back(0, n);
	events.emplace_back(x, n + 1);
	sort(events.begin(), events.end());
	int p0, px; // p0 = index of starting position, px = index of destination
	vector<int> pz(n); // pz[i] = position of hammer i
	for (int i = 0; i < events.size(); i++) {
		if (events[i].second == n) {
			p0 = i;
		} else if (events[i].second == n + 1) {
			px = i;
		} else if (events[i].second < 0) {
			pz[~events[i].second] = i;
		}
	}
	const long long INF = 1e18;
	long long ans = INF;
	debug(events);
	// dp[left event index][right event index][which side you are on] = min answer
	vector<vector<vector<long long>>> dp(events.size(), vector<vector<long long>>(events.size(), vector<long long>(2, INF)));
	dp[p0][p0][0] = 0;
	for (int l = p0; l >= 0; l--) {
		for (int r = p0; r < events.size(); r++) {
			for (int d = 0; d < 2; d++) {
				bool can_move_left = l - 1 >= 0 && (events[l - 1].second < 0 || events[l - 1].second >= n || l <= pz[events[l - 1].second] && pz[events[l - 1].second] <= r);
				if (can_move_left) {
					dp[l - 1][r][0] = min(dp[l - 1][r][0], dp[l][r][d] + (events[l].first - events[l - 1].first) + d * (events[r].first - events[l].first));
				}
				bool can_move_right = r + 1 < events.size() && (events[r + 1].second < 0 || events[r + 1].second >= n || l <= pz[events[r + 1].second] && pz[events[r + 1].second] <= r);
				if (can_move_right) {
					dp[l][r + 1][1] = min(dp[l][r + 1][1], dp[l][r][d] + (events[r + 1].first - events[r].first) + (!d) * (events[r].first - events[l].first));
				}
				if (l <= px && px <= r) {
					ans = min(ans, dp[l][r][d]);
				}
			}
		}
	}
	debug(dp[p0 - 1][p0][0]);
	cout << (ans == INF ? -1 : ans) << '\n';
}

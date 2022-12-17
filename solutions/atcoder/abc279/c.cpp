// Author: Aaron He
// Created: 26 November 2022 (Saturday)
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> s(h), t(h);
	for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < h; i++) {
		cin >> t[i];
	}
	vector<string> cs(w), ct(w);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cs[i] += s[j][i];
			ct[i] += t[j][i];
		}
	}
	sort(cs.begin(), cs.end());
	sort(ct.begin(), ct.end());
	cout << (ct == cs ? "Yes" : "No") << '\n';
}

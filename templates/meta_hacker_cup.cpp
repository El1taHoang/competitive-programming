// Author: Aaron He
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define setio(file) freopen(&(string(file) + "_input.txt")[0], "r", stdin); freopen(&(string(file) + "_output.txt")[0], "w", stdout)
#define setiov(file) freopen(&(string(file) + "_validation_input.txt")[0], "r", stdin); freopen(&(string(file) + "_validation_output.txt")[0], "w", stdout)

void solve() {
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cerr << "Solving Case #" << i << " out of " << t << "...\n";
		cout << "Case #" << i << ": ";
		solve();
	}
}

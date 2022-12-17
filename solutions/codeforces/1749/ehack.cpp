#include <iostream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

int main() {
	mt19937 rng(1);
	int t = 1;
	cout << t << '\n';
	for (int test = 0; test < t; test++) {
		int n = 632, m = 632;
		cout << n << ' ' << m << '\n';
		vector<vector<bool>> grid(n + 1, vector<bool>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int x = uniform_int_distribution<int>(1, 1e9)(rng);
				if (x % 100 == 0 && !grid[i - 1][j] && !grid[i][j - 1]) {
					grid[i][j] = true;
					cout << '#';
				} else {
					cout << '.';
				}
			}
			cout << '\n';
		}
	}
}


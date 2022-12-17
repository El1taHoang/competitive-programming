#ifdef DEBUG
#include "../../debug.cpp"
#else
#define debug(...) ""
#endif
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = 9;
	vector<string> grid(n);
	vector<vector<bool>> pawn(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
		for (int j = 0; j < n; j++) {
			pawn[i][j] = grid[i][j] == '#';
		}
	}
	auto bound = [n] (int i) {
		return i >= 0 && i < n;
	};
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int di = 0; di < n; di++) {
				for (int dj = 1; dj < n; dj++) {
					if (bound(i + di) && bound(j + dj) && bound(i + di + dj) && bound(j + dj - di) && bound(i + dj) && bound(j - di)) {
						ans += pawn[i][j] && pawn[i + di][j + dj] && pawn[i + di + dj][j + dj - di] && pawn[i + dj][j - di];
					}
				}
			}
		}
	}
	cout << ans << '\n';
}


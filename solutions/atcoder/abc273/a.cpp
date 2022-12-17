// Author: Aaron He
// Created: Sun, 30 Oct 2022
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 1; i <= n; i++) 
		ans *= i;
	cout << ans << '\n';
}

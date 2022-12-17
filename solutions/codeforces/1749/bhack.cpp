#include <iostream>
#include <random>
#include <chrono>
#include <vector>
using namespace std;

int main() {
	mt19937 rng(1);
	int t = 1e4;
	cout << t << '\n';
	int n1 = 1e5;
	int n2 = 2e5 - n1;
	for (int test = 0; test < t; test++) {
		int n;
		if (test == 0) {
			n = n1;
		} else {
			n = n2/(t - 1);
		}
		cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			int x = uniform_int_distribution<int>(1, 1e9)(rng);
			cout << x << " \n"[i == n];
		}
		for (int j = 0; j < n; j++) {
			int x = uniform_int_distribution<int>(1, 1e9)(rng);
			cout << x << " \n"[j == n - 1];
		}
	}
}


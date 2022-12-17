// Author: Aaron He
// Created: 12 December 2022 (Monday)
#include <chrono>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

mt19937 rng(3);

int uniform(int a, int b) {
	return rng() % (b - a + 1) + a;
}

int main() {
	int n = 1e6;
	int mx = 1e7;
	//int x = 9999991;
	//int x = 9699690;
	//int x = 8648640;
	int x = 9790577; // 3978 ms
	//int x = 9500021; 3961 ms
	//int x = 8500007; 3946 ms
	//int x = 9000011;
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		int r1 = uniform(1e5, int(1e7 - x));
		int r2 = x + r1;
		cout << r1 << ' ' << r2 << '\n';
	}
}

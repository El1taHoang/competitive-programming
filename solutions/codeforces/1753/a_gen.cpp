#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ofstream cout("a.in");
	int n;
	cin >> n;
	int p3 = 1;
	for (int i = 0; i < n; i++) p3 *= 3;
	cout << p3 << '\n';
	for (int i = 0; i < p3; i++) {
		int j = i;
		cout << n << '\n';
		for (int k = 0; k < n; k++) {
			cout << (j % 3 - 1) << ' ';
			j /= 3;
		}
		cout << '\n';
	}
}


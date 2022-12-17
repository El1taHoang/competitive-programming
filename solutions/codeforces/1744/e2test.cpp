#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			for (int c = a + 1; c < 10; c++) {
				for (int d = b + 1; b < 10; b++) {
					t++;
					cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
				}
			}
		}
	}
	cout << t << '\n';
}


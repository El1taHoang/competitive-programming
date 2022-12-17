#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	int mxh = 0;
	int mxi;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > mxh) {
			mxh = a[i];
			mxi = i;
		}
	}
	cout << mxi + 1 << '\n';
}


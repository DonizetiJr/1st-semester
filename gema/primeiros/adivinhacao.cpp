#include <bits/stdc++.h>

using namespace std;

int main (void) {
	int r;
	// 1 2 3 4 5 6 7 8 9 10
	cout << 5 << endl;
	cin >> r;
	if (r == 1) {
		cout << 8 << endl;
		cin >> r;
		if (r == 1) {
			cout << 9 << endl;
			cin >> r;
			if (r == 1) cout << 10 << endl;
		} else {
			cout << 6 << endl;
			cin >> r;
			if (r == 1) cout << 7 << endl;
		}	
	} else if (r == 0) {
		cout << 3 << endl;
		cin >> r;
		if (r == 1) cout << 4 << endl;
		else {
			cout << 1 << endl;
			cin >> r;
			if (r == 1) cout << 2 << endl;
		}
	} 

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

long double fat(int x) {
	if(x == 0)
		return 1;
	else
		return x*fat(x-1);
}

int main (void) {

	int n, k;

	cin >> n;
	cin >> k;

	cout << fat(n) / (fat(k) * fat(n - k)) << endl;

}
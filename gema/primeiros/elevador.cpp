#include <bits/stdc++.h>
#include <cstdio>

using namespace std;


int main(void) {

	int n;
	cin >> n;

	int last = -1;
	int res = 0;

	for (int i = 0; i < n ; i++) {
		int x;
		cin >> x;
		if (last != -1) {
			res += abs (x - last);
		}
		last= x;
	}

	return 0;
}


/*

	//operadores binários

		if(a and b);
		if(a < n or b < m);


*/
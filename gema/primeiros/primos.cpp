#include <bits/stdc++.h>

using namespace std;

int main(void) {

	int p;
	cin >> p;
	bool primo = true;

	for (int i = 2;  i < sqrt(p); ++i){
		if (p%i == 0) {
			cout << i << " " << p/i << endl;
		}
	}
	

	return 0;
}
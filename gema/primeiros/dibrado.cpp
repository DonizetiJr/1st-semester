#include <bits/stdc++.h>

using namespace std;

int main (void) {

	long long int n, i, escolas, total;

	cin >> n;

	if (n == 1){
	return 0;
	}
	else {	
		for(i = 0; i < n; i++){
			cin >> escolas;
			total += escolas;
		}

		if(total % 2 == 0) {
			cout << "O Loppa vai mandar bem" << endl;
		}
		else {
			cout << "O Loppa vai ficar pistola" << endl;
		}
	}
}
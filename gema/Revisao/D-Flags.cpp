#include <bits/stdc++.h>

using namespace std;

long double fat(int x) {
	if(x == 0)
		return 1;
	else
		return x*fat(x-1);
}

int main(void) {

	int n, i, resultado = 1;
	cin >> n;
	
	for(i=0;i<n-1;i++)
		resultado *= 2;

	

	cout << resultado << endl;

	return 0;
}
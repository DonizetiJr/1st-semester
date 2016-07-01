#include <bits/stdc++.h>

using namespace std;

int main (void) {

	int n;
	cin >> n;

	long long int conjunto[n], maior, menor;

	int i, j;

	for (i = 0; i < n; i++){
		cin >> conjunto[i];
	}


	if (conjunto[0] > conjunto[1]){
			maior = conjunto[0]; 
			menor = conjunto[1]; 
		}
		else {
			maior = conjunto[1];
			menor = conjunto[0]; 
		}

		
		for (j = 2; j < n; j++) {


			if (conjunto[j] > conjunto[j - 1]) {
				
				if(conjunto[j] > maior) 
					maior = conjunto[j];
			}
			else {
				if (conjunto[j] < menor)
					menor = conjunto[j];
					
			}
			
		}
	
		long long int resultado = maior - menor;
		
		cout << resultado << endl;




}
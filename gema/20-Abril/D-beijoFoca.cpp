const int N = 1000001;
int div[N];
// not_prime[i] é 1 se o número i não é primo!
bool not_prime[N];

void crivo () {
	for (int i = 2; i < N; ++i) {
		if (!div[i]) {
			for (int j = i+i; j < N; j+= i) {
				div[j] = i;
			}
		}
	}
}

void fatora(int x) {
	while (div[x] > 0) {
		cout << div[x] << endl;
		x = x/div[x];
	}
	cout <<x << endl;
}


int main (void) {
    


    return 0;
}



/* for (int i = 2; i < N; ++i) {
        if (not_prime[i] == false) {
            for (int x = i+i; x < N; x += i) {
                not_prime[x] = true;
            }
        }
    }
}
*/

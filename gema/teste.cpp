#include <iostream>
#include <cmath>

using namespace std;

double fatorial(int n) {
	if(n != 0) return n*fatorial(n-1);
	else return 1;
}

double sin(double angulo) {
	int i, sinal = -1;
	double termo, seno = 0;

	for(i=1; i < 600; i += 2) {
		termo = (double)pow(angulo,i)/fatorial(i);
		sinal = -sinal;
		seno += (sinal*termo);
	}
	return seno;
}

int main(void) {
	double angulo, resultado;

	cin >> angulo;
	resultado = sin(angulo);

	cout << resultado << endl;

	return 0;
}
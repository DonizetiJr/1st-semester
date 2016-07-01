#include <stdio.h>
#include <math.h>

int main() {

	int inteiro, arredondabaixo, arredondacima;
	double a;
	scanf("%lf", &a);

	inteiro = (int)a;
	arredondabaixo = floor(a);
	arredondacima = ceil(a);
	
	printf("%d\n", inteiro);
	
	printf("%.4lf\n", a - inteiro);

	if(a - inteiro <= 0.5) {
		printf("%d\n", arredondabaixo);
	}
	else {
		printf("%d\n", arredondacima);
	}

	return 0;
}


/*

math.h - Contém protótipos de funções da biblioteca matemática.
Algumas funções:

** é necessário compilar com -lm e não -o! **


double sin (double x);
· seno de x
· sintaxe: sin(x);


double cos (double x);
· co-seno de x
· sintaxe: cos(real);


double tan (double x);
· tangente de x
· sintaxe: tan(x);


double sqrt (double x);
· raiz quadrada de x (x>=0)
· sintaxe: sqrt(x);


double exp (double x);
· ex (e é aproximadamente 2,718)
· sintaxe: exp(x);


double log (double x);
· ln(x) (logaritmo natural- base e) (x>0)
· sintaxe: log (x);


double log10 (double x);
· log10(x) (logaritmo base 10) (x>0)
· sintaxe: log10 (x);

double pow (double x, double y);
· xy (erro de domínio se x=0 e y<=0, ou se x<0 e y não for inteiro)
· sintaxe: pow (x, y);


double ceil (double x);
· menor inteiro não menor que x (teto x)
· sintaxe: ceil (x);


double floor(double x);
· maior inteiro não maior que x (piso x)
· sintaxe: floor(x);


double fabs(double x);
· valor absoluto de x, x
· sintaxe: fabs (x);

*/
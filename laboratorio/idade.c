#include <stdlib.h>
#include <stdio.h>


int main( int argc, char *argv[ ] ) {

	int mesnasc, mes,
		 dianasc, dia,
		 anonasc, ano;
	int idade;

	scanf("%d %d %d", &dianasc, &mesnasc, &anonasc);
	scanf("%d %d %d", &dia, &mes, &ano);

	
		idade = ano - anonasc;

		if(mes == mesnasc){
			if(dia < dianasc){
				idade -= 1;
			}
		}
		else if(mes < mesnasc) {
			idade -= 1;
		}




	printf("Idade: %d", idade);

return 0;
}
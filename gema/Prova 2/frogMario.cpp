/*
Como o máximo é 10⁶, é necssário saber se pegou no máximo 20(2²⁰) power-ups
f(localização, q(quantidade power-ups já pegou)
	se (x >= n) retorna 0
	se s(x) = buraco
		retorna infinito
	se s(x) = posição normal
		retorna  1+f(x+1, q)
	se s(x) = power-up
		retorna min(f(x+1,q)+1) => f(x+2⁹⁺¹, q+1)
*/
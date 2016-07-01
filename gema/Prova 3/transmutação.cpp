/*É sábido que para obter a Pedra Filosofal, é preciso transmutar vidas humanas. 
O grande alquimista Loppão conseguiu algumas cobaias.

Loppão posicionou N (numeradas de 1 a N) primeiras cobaias em um círculo, conectando-as 
por meio de alquimia. No começo, Loppão ligou a pessoa de número 1 à de número 2, a de 
número 2 à de número 3 e assim por diante, até conectar a pessoa de número N à pessoa 
de número 1. Entretanto, isso ainda não foi suficiente. Loppão resolveu então adicionar 
pessoas ao grupo. Para isso, resolveu seguir a seguinte regra: cada nova pessoa seria 
conectada a alguma outra pessoa já presente no ritual.

Posteriormente, foi descoberto que um círculo ainda continuará funcionando mesmo se for 
quebrado. Nesse caso, a força do círculo (agora deformado) será proporcional ao número 

de pessoas conectadas nesse círculo. Duas pessoas estão conectadas se há um caminho de 
pessoas conectadas entre elas. O nosso herói, Mustango Shi, quer cancelar a transmutação, 
mas só tem força para 1) Desfazer duas das ligações originais de Loppão ou 2) Desfazer uma 
ligação original e uma das que aconteceram depois.

Descubra quais ligações ele deve cortar de forma a minimizar a maior força dos círculos que sobrarem.

Input
A entrada começa com dois inteiros, N e K, (1 ≤ N, K ≤ 106), o número de pessoas no círculo original de Loppa e o número de pessoas adicionadas posteriormente ao círculo.

Seguem K linhas, cada uma descrevendo com quem a k-ésima pessoa adicionada posteriormente foi conectada.

Note que os índices de 1 a N referem-se à pessoas originais do círculo, e os índices de N + 1 a N + K referem-se às pessoas adicionais.

Output
Imprima a força do círculo mais forte após Mustango cortar duas conexões de forma ótima.

Example
input
5 7
4
1
4
6
3
4
7
output
6
*/


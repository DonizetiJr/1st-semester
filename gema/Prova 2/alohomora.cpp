/*	MAIS DIFICIL DA PROVA

	Não é fácil ser um mago. Por exemplo, se você um dia precisar enfrentar um outro mago em 
	uma batalha mortal, deverá gritar o nome de várias magias consecutivamente, e isso pode 
	cansar a voz mesmo dos cantores mais treinados.

Por isso, a Academia de Magia decidiu que um mago só pode utilizar uma magia seguida de outra 
se a última letra da primeira magia for igual à primeira letra da segunda magia.

Vamos considerar um Corpus Mágico um conjunto de magias que podem ser utilizadas. Dizemos que 
duas magias A e B são compatíveis se é possível conjurar uma magia após a outra. Dizemos que 
duas magias são da mesma categoria se elas começam e terminam com a mesma letra. Vamos chamar 
a categoria da palavra p de Cp. Duas palavras da mesma categoria não podem ser encadeadas.

A Academia de Magia impõe mais uma restrição sobre os Corpus Mágicos. Cada palavra pode ser 
compatível com palavras de várias categorias - porém, para cada categoria Ci, só existe uma 
única categoria Cj tal que Cj seja compatível com Ci. É garantido que todos os corpus mágicos
 obedecem essa restrição.

Um professor de defesa contra as artes das trevas maluco resolveu que não quer que nenhum 
de seus alunos seja capaz de conjurar duas magias compatíveis. Apesar disso, ele precisa 
ensinar o maior número de magias possível para seus alunos, e com certeza precisa ensinar 
a magia alohomora, que está presente em todos os corpus mágicos da Academia. O professor 
não liga que os alunos possam conjurar a alohomora com outra magia compatível - mas para 
todas as outras magias que os alunos aprenderem, eles não podem conseguir fazê-lo.

Dado um Corpus Mágico, ajude esse professor a descobrir o número máximo de magias que ele 
pode ensinar à seus alunos sem que eles sejam capazes de encadear nenhuma delas.

Input
A entrada começa com um número, N, o número de magias (1 ≤ N ≤ 105). Seguem então N linhas, 
cada uma descrevendo uma magia. A primeira magia sempre será alohomora. Os nomes das magias 
possuem apenas caracteres minúsculos e têm até 20 caracteres.

Example
input
6
alohomora
avis
anteoculatia
skurge
erecto
episkey

output
4

Note
Repare que a relação de compatibilidade não é reflexiva. Por exemplo, abc é compatível com cbd, mas cbd não é compatível com abc.

Nesse caso, a melhor solução é ensinar as magias alhomora, anteoculatia, erecto e episkey

	obs: alohomora é excessão, ou seja, deve-se ignora-lo e somar 1 no final
	
*/
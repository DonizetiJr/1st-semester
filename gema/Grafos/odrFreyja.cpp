/* MAIS DIFICIL

Freyja é a deusa do amor e da fertilidade na mitologia nórdica. Diz-se que metade dos guerreiros 
mortos em batalha vão para os halls de Odin, Valhalla, e a outra metade vão para o paraíso de Fólkvangr, 
governado por ela.

Apesar de ser a deusa do amor, o marido de Freyja, Óðr, quase nunca se encontra presente. 
Acreditava-se que Freyja chorava lágrimas de ouro vermelho por ele.

Durante um episódia da Edda, dois guerreiros humanos, Sinfjötli e Hlöd, conseguiram ascender
 vivos à Fólkvangr em busca do amor de Freyja. Apesar de amar seu marido, Freyja decidiu que daria 
 chance aos dois humanos caso eles resolvessem seu desafio.

O desafio de Freyja era o seguinte. Ela criou um circulo com N pedras para o primeiro pretendente 
e M pedras para o segundo pretendente. Ela então ordenou que os dois dessem um pulo por vez - ou 
para a pedra à esquerda ou para a pedra à direita. Não é necessário que os dois se alternem para dar 
os pulos - é apenas necessário que eles não pulem juntos.

Freyja decidiu que irá casar-se com os dois humanos se eles conseguirem voltar à posição inicial 
passando por todas as configurações possíveis exatamente uma vez. Uma configuração consiste da posição 
do primeiro pretendente no primeiro círculo e a posição do segundo pretendente no segundo círculo.

Você deve imprimir a ordem de pulos dos dois pretendentes para que eles consigam o amor de Freyja. 
Imprima uma ordem por linha, da seguinte forma:

1 H

1 A

2 A

2 H

Onde (1, 2) se refere ao primeiro ou segunto amante e H e A se referem à um pulo no sentido horário ou anti-horário. 
Caso não exista solução, imprima -1.

Input
A entrada contém dois inteiros, N e M (2 ≤ N, M ≤ 103), o número de pedras do círculo do primeiro e do segundo amante.

Output
Imprima uma sequência de jogadas válidas para os dois jogadores passarem por todas as configurações sem repetições. 
Caso exista mais de uma solução, pode imprimir qualquer uma delas.
*/

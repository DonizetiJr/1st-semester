/*Lubuntinho recebeu de seu avô uma lista de palavras codificadas e a chatíssima tarefa de decodificar
 todas elas. Não entendeu a vinda súbita dessa ordem e o seu motivo - algo relacionado a super vilania 
 ou coisa assim - mas deve cumprir a tarefa, ou corre risco de ficar sem seus brinquedos.

Após encarar a lista de palavras por algum tempo, percebeu que era capaz de montar certas palavras 
inteligíveis reordenando as letras das palavras codificadas. Supôs, então, que a codificação envolvia 
simplesmente reordenação de letras. Finalmente, percebeu como fazer para decodificar: bastava escrever 
a palavra codificada em linhas de um certo tamanho fixo n - tamanho este que ele precisava encontrar 

por tentativa e erro - e depois ler a palavra formada pela consideração das letras de cima para baixo 
e da esquerda para a direita. Por exemplo, se a palavra codificada for "MNAEESGM" e o n descoberto for 2, teremos:

M N A E

E S G M

E a palavra decodificada será "MENSAGEM".

Lubuntinho já descobriu qual o n necessário para decodificar cada palavra, mas, não surpreendentemente, 
está com preguiça de decodificar todas elas e ordenou que você o fizesse para ele. Você não quer saber 
o que acontecerá se você desobedecer.

Input
A primeira linha da entrada contém o número de linhas descoberto n, 1 ≤ n ≤ 1000. A segunda linha contém 
uma palavra, a qual consiste apenas de letras maiúsculas de A a Z e cujo tamanho não excede 1000 caracteres.
 É garantido que o tamanho da palavra é múltiplo de n.

Output
Imprima uma única linha contendo a palavra descriptografada.

Examples
input
2
MNAEESGM
output
MENSAGEM

input
4
MAEGNESM
output
MENSAGEM

input
6
ZTOEMRBSEORN
output
ZOMBERTERSON
*/
/* Lubuntu tem pelos próximos anos de sua vida a difícil tarefa de ensinar seu neto, Lubuntinho, 
a ser um super vilão como o avô. A arte de ser um super vilão envolve múltiplas disciplinas, e uma 
delas é criptografia - um super vilão deve estar sempre pronto para trabalhar com mensagens secretas. 
Por isso, Lubuntu deseja passar a seu neto uma lista com várias palavras codificadas para que ele quebre 
a cabeça e as descodifique por conta própria. Lubuntu já pensou em como irá codificar as palavras. 
Ele o fará da seguinte maneira:

Primeiro, ele escolherá um número n. Depois, escreverá as letras da palavra verticalmente em colunas 
de tamanho n. Por exemplo, se a palavra for "MENSAGEM" e n for 2, teremos:

M N A E

E S G M

Por último, ele considerará a palavra que é obtida lendo-se o resultado obtido linha por linha. 
No exemplo acima, a palavra seria "MNAEESGM". Esta é a palavra codificada.

Não surpreendentemente, Lubuntu está com preguiça de codificar suas palavras e ordenou que você o fizesse 
para ele. Você não quer saber o que acontecerá se você desobedecer.

Input
A primeira linha da entrada contém o tamanho das colunas n, 1 ≤ n ≤ 1000. A segunda linha contém uma palavra,
a qual consiste apenas de letras maiúsculas de A a Z e cujo tamanho não excede 1000 caracteres. 
A fim de facilitar um pouco para seu neto, Lubuntu estabeleceu que o tamanho da palavra será sempre múltiplo de n.

Output
Imprima uma única linha contendo a palavra criptografada.

Examples
input
2
MENSAGEM
output
MNAEESGM

input
4
MENSAGEM
output
MAEGNESM

input
6
ZOMBERTERSON
output
ZTOEMRBSEORN
*/
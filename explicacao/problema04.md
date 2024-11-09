## beecrowd | 1903
### Cadeia Alimentar

Na viagem de Bino, ele desenhou algumas cadeias alimentares dos seres de Binox. Porém ele notou que em algumas cadeias, todos os pares de espécies se relacionavam (diretamente ou indiretamente). Ele denominou essas cadeias de Cadeias Boladas.

Representando a cadeia alimentar como um grafo, todos os pares de espécies (u, v) se relacionam se existe um caminho de u para v OU um caminho de v para u.


![img](..\assets\beeCrowd1903.png)


Dado uma cadeia alimentar, Bino quer saber se ela é uma Cadeia Bolada ou não.

### Entrada
A entrada consiste em múltiplas linhas. A primeira linha contém dois inteiros N (1 ≤ N ≤ 100000) e M (1 ≤ M ≤ 1000000), representando a quantidade de espécies e o número de relações respectivamente. As próximas M linhas contêm dois inteiros U (1 ≤ U ≤ N) e V (1 ≤ V ≤ N), representando que existe uma relação unidirecional entre U e V.

### Saída
Imprima uma linha com a mensagem "Bolada" (sem aspas) se a cadeia for uma Cadeia Bolada, ou "Nao Bolada" caso contrário.